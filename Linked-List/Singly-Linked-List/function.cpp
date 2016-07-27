// This program shows you how to implement a linked list and other operations on them.
// Please consider the requirement.png file to see the requirements and then review the code.


#include "function.h"
#include <fstream>
#include <iostream>
using namespace std;
void input(Node* &pH) {
	ifstream fin;
	int n;
	fin.open("input.txt");
	if (fin) {
		fin >> n;
		Node* cur = new Node;
		if ((cur != NULL) && (!fin.eof())) {
			pH = cur;
			cur->data = n;
			cur->next = NULL;
		}
		while (!fin.eof()) {
			fin >> n;
			cur->next = new Node;
			if (cur->next != NULL) {
				cur = cur->next;
				cur->data = n;
				cur->next = NULL;
			}
		}
		fin.close();
	}
	else cout<< " cannot open file";
}
void output1(Node *pH) {
	ofstream fout;
	fout.open("1_output_reversed.txt");
	if (!fout)
		cout << "cannot open output file";
	else {
		while (pH != NULL) {
			fout << pH->data << " ";
			pH = pH->next;
		}
	}
	fout.close();
}
void output2(Node *pH) {
	ofstream fout;
	fout.open("2_output_even_deleted.txt");
	if (!fout)
		cout << "cannot open output file";
	else {
		while (pH != NULL) {
			fout << pH->data << " ";
			pH = pH->next;
		}
	}
	fout.close();
}
Node* reverse(Node* pH) {
	Node* nextNode;
	Node* curNode;
	if (pH == NULL)
		return pH;
	else {
		curNode = pH;
		nextNode = curNode->next;
		curNode->next = NULL;
		while (nextNode != NULL) {
			Node *temp = nextNode->next;
			nextNode->next = curNode;
			curNode = nextNode;
			nextNode = temp;

		}
	}
	return curNode;

}
void removeEven(Node *&pH) {
	Node* cur;
	Node* temp;
	cur = pH;
	while (pH != NULL && pH->data % 2 == 0) {
		temp = pH;
		pH = pH->next;
		delete temp;
		cur = pH;
	}

	if (pH != NULL)
		cur = pH;
	else
		return;

	while (cur -> next != NULL) {
		if (cur->next->data % 2 == 0) {
			temp = cur->next;
			cur->next = temp->next;
			delete temp;
		}
		else
			cur = cur->next;
	}
}
Node* insertSome(Node* &pH) {
	int count = 2;
	Node* current = pH;
	if (current == NULL)
		return 0;
	if (pH == NULL)
		return 0;
	Node* insertLoL;
	insertLoL = new Node;
	if (insertLoL == NULL)
		return 0;
	insertLoL->data = count;
	insertLoL->next =pH;
	pH = insertLoL;
	current = pH;
	current = current->next;
	while (current->next != NULL) {
		count += 2;
		Node* insertNew;
		insertNew = new Node;
		if (insertNew == NULL)
			return 0;
		insertNew->data = count;
		insertNew->next = current->next;
		current->next = insertNew;
		current = insertNew->next;
	}
	return pH;
}
void output3(Node *pH) {
	ofstream fout;
	fout.open("3_output_even_inserted.txt");
	if (!fout)
		cout << "cannot open output file";
	else {
		while (pH != NULL) {
			fout << pH->data << " ";
			pH = pH->next;
		}
	}
	fout.close();
}
void removeall(Node* &pH)
{
	Node* temp = pH;
	while (temp != NULL)
	{
		pH = pH->next;
		delete temp;
		temp = pH;
	}
	delete pH;
	return;
}
void input2(Node* &pH1) {
	ifstream fin;
	int n;
	fin.open("input2.txt");
	if (fin) {
		fin >> n;
		Node* cur = new Node;
		if ((cur != NULL) && (!fin.eof())) {
			pH1 = cur;
			cur->data = n;
			cur->next = NULL;
		}
		while (!fin.eof()) {
			fin >> n;
			cur->next = new Node;
			if (cur->next != NULL) {
				cur = cur->next;
				cur->data = n;
				cur->next = NULL;
			}
		}
		fin.close();
	}
	else cout << " cannot open file";
}
void joinNode(Node* pH1, Node* pH2) {
	ofstream fout;
	fout.open("4_joined.txt");
	Node* cur1;
	cur1 = pH1;
	Node* cur2;
	cur2 = pH2;
	if (cur1 == NULL || cur2 == NULL)
		return;
	while (cur1 != NULL) {
		while (cur2 != NULL) {
			if (cur2->data == cur1->data) {
				fout << cur2->data << " ";
			}
			cur2 = cur2->next;
		}
		cur2 = pH2;
		cur1 = cur1->next;
	}
	fout.close();
}
bool checkLoop(Node *pH1) {
	Node* slowNode = pH1;
	if (slowNode == NULL)
		return false;
	Node* fastNode = slowNode->next;
	if (fastNode == NULL)
		return false;
	while (fastNode != NULL) {
		if (fastNode->data == slowNode->data) 
			return true;
		if (fastNode->next == NULL)
			return false;
		fastNode = fastNode->next->next;
		slowNode = slowNode->next;
	}
	return false;
}
void output4(Node *pH) {
	ofstream fout;
	fout.open("5_loop.txt");
	if (!fout)
		cout << "cannot open output file";
	else {
		if (checkLoop(pH) == true)
			fout << " TRUE";
		else fout << "FALSE";
		}
	
	fout.close();
}