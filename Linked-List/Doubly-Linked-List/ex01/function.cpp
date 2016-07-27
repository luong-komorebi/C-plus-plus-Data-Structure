#include "function.h"
#include <iostream>
using namespace std;
#include <fstream>
DLinkedList::DLinkedList(void) {
	cout << " Initiating Linked List \n";
	pHead = NULL;
	pTail = NULL;
}
void DLinkedList::input(){
	ifstream fin;
	int n;
	fin.open("input.txt");
	if (fin) {
		fin >> n;
		Node* cur = new Node;
		if ((cur != NULL) && (!fin.eof())) {
			pHead = cur;
			cur->data = n;
			cur->pNext = NULL;
			cur->pPrev = NULL;
		}
		while (!fin.eof()) {
			fin >> n;
			cur->pNext = new Node;
			if (cur->pNext != NULL) {
				cur->pNext->data = n;
				cur->pNext->pNext = NULL;
				cur->pNext->pPrev = cur;
				cur = cur->pNext;
			}
			else pTail = cur;
		}
		pTail = cur;
		fin.close();
	}
	else cout << " cannot open file";
}

void DLinkedList::PrintOutTheList() {
	Node* cur = pHead;	
	if (pHead == NULL) {
		cout << " No element in the list to print out.";
		return;
	}
	cout << " Linked list:\n";
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->pNext;
	}
}
void DLinkedList::FindX( int x) {
	Node* cur = pHead;
	int pos=0;
	int count = 0;
	if (pHead == NULL) {
		cout << " Cant find X in the list ";
		return;
	}
	while (cur != NULL) {
		pos++;
		if (cur->data == x) {
			cout << " X found! Found at " << pos << " position in the list" << endl;
			count++;
		}
		cur = cur->pNext;
	}
	if (cur == NULL && count == 0)
		cout << " cant find!";
}
void DLinkedList::Add2TheBeginning(int a) {
	Node* insert = new Node;
	insert->data = a;
	insert->pNext = NULL;
	insert->pPrev = NULL;
	if (pHead == NULL) {
		pHead = insert;
		return;
	}
	else {
		insert->pNext = pHead;
		pHead->pPrev = insert;
		pHead = insert;
	}
}
void DLinkedList::Add2TheEnd(int b) {
	Node* insert = new Node;
	insert->data = b;
	insert->pNext = NULL;
	insert->pPrev = NULL;
	if (pHead == NULL) {
		pHead = insert;
		return;
	}
	Node* cur = pHead;
	while (cur != NULL) {
		if (cur->pNext == NULL) {
			cur->pNext = insert;
			insert->pPrev = cur;
			cur = insert;
		}
		 cur = cur->pNext;
	}
}
void DLinkedList::AddYbeforeX(int x, int y) {
	Node* insert = new Node;
	insert->data = y;
	insert->pPrev = NULL;
	insert->pNext = NULL;
	if (pHead == NULL) {
		cout << " Cant find anything in the list ";
		return;
	}
	Node* cur = pHead;
	if (cur->data == x) {
		Add2TheBeginning(y);
	}
	while (cur->pNext!= NULL) {
		if (cur->pNext->data == x) {
			insert->pNext = cur->pNext;
			cur->pPrev = insert;
			insert->pPrev = cur;
			cur->pNext = insert;
		}
		cur = cur->pNext;
	}
}
void DLinkedList::DeleteThe1stNode() {
	if (pHead == NULL) {
		cout << " Nothing to delete\n";
		return;
	}
	if (pHead->pNext == NULL) {
		delete pHead;
		return;
	}
	Node* temp = pHead;
	pHead = pHead->pNext;
	delete temp;
	pHead->pPrev = NULL;
}
void DLinkedList::DeleteTheLastNode() {
	Node* temp = pTail;
	pTail = pTail->pPrev;
	delete temp;
	pTail->pNext = NULL;
}
void DLinkedList::DeleteAllX(int x) {
	Node* cur = pHead;
	if (pHead == NULL) {
		cout << " Nothing to delete!" << endl;
		return;
	}
	if( pHead->pNext==NULL ){
		if ( pHead->data==x)
			delete pHead;
		return;
	}
	while (pHead->pNext != NULL) {
		if (cur->pNext->data == x) {
			Node* temp = cur->pNext;
			if (temp->pNext == NULL) {
				cur->pNext = NULL;
				delete temp;
				return;
			}
			cur->pNext = temp->pNext;
			temp->pNext->pPrev = cur;
			delete temp;
		}
		cur = cur->pNext;
	}
}
DLinkedList::~DLinkedList(void) {
	while (pHead != NULL) {
		Node* temp = pHead;
		pHead = pHead->pNext;
		delete temp;
	}
	pTail = NULL;
}
