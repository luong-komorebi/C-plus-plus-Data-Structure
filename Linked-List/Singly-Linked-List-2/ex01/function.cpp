// Please refer to the requiremnet.png file to see what i am doing here!

#include "function.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <math.h>

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
	else cout << " cannot open file";
}
void input2(Node* &pH){
	ifstream fin;
	int n;
	fin.open("input2.txt");
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
	else cout << " cannot open file";

}
Node* insertNew(Node* pH, int n) {
	Node* cur = pH;
	Node* insert = new Node;
	if (cur == NULL || insert==NULL)
		return NULL;
	insert->data = n;
	insert->next = NULL;
	while (cur != NULL) {
		if ( cur->data <=n){
			if (cur->next == NULL) {
				cur->next = insert;
				break;
			}
			else {
				if (cur->next->data > n) {
					insert->next = cur->next;
					cur->next = insert;
					cur = insert;
				}
			}
		}
		cur = cur->next;
	}
	return pH;
}
Node* inOut(Node* pH) {
	Node* cur = pH;
	Node* out = new Node;
	if (cur == NULL || out == NULL)
		return NULL ;
	if (cur->next == NULL)
		return cur;
	Node* temp = out;
	out->data = cur->data;
	out->next = new Node;
	while (cur->next != NULL) {
		cur = cur->next;
		out->next = new Node;
		out->next->data = out->data + cur->data;
		out = out->next;
		out->next = NULL;
	}
	return temp;

}
void  rearrange(Node* pH, Node* pH2) {
	Node* start1 = pH;
	Node* start2 = NULL ;

	int numberOfNodes = 0;
	if (pH == NULL) {
		return;
	}
	if (pH->next == NULL) {
		pH2 = NULL; 
		return;
	}
	if (pH->next->next == NULL) {
		start1 = start1->next;
		pH2 = start1;
		pH2->next = NULL;
		pH->next = NULL;
	}
	while (start1 != NULL) {
		start1 = start1->next;
		numberOfNodes++;
	}
	start1 = pH;
	for (int i = 1; i <= numberOfNodes - 1; i+=2) {
		if (i == 1) {
			pH2 = start1->next;
			start1->next = start1->next->next;
			start2 = pH2;
			start1 = start1->next;
			continue;
		}
		start2->next = start1->next;
		start1->next = start1->next->next;
		start2 = start2->next;
		start1 = start1->next;
		if (i == numberOfNodes - 1)
			start1 = NULL;
		

	}
	cout << " 3.  ";
	output(pH);
	output(pH2);
}
Node* combine(Node* pH, Node* pH3) {
	Node* travel1 = pH;
	Node* travel2 = pH3;
	Node* travel1next = NULL;
	Node* travel2next = NULL;
	int Population1 = 0;
	int Population2 = 0;
	if (pH ==NULL && pH3==NULL )
		return NULL;
	if (pH3 == NULL)
		return pH;
	if (pH == NULL)
		return pH3;
	while (travel1 != NULL) {
		travel1=travel1->next;
		Population1++;
	}
	while (travel2 != NULL) {
		travel2 = travel2->next;
		Population2++;
	}
	if (Population1 >= Population2) {
		travel1 = pH;
		travel2 = pH3;
	}
	else {
		travel1 = pH3;
		travel2 = pH;
	}
	while (travel2 != NULL) {
		travel1next = travel1->next;
		travel2next = travel2->next;
		travel2->next = travel1next;
		travel1->next = travel2;
		travel1 = travel1next;
		travel2 = travel2next;
	}
	if (Population1 >= Population2) 
		return pH;	
	else 
		return pH3;
	
}
Node* joining(Node*pH, Node*pH3) {
	Node* temp = pH;
	Node* temp2 = pH3;
	if (pH == NULL && pH3 == NULL)
		return NULL;
	if (pH == NULL)
		return pH3;
	if (pH3 == NULL)
		return pH;
	while (temp != NULL) {
		if( temp->next== NULL){
			temp->next = temp2;
			break;
		}
		else temp = temp->next;
	}
	return pH;

}
int computeintoInteger(Node* pH) {
	Node* cur = pH;
	int k = 0;
	if (cur == NULL) {
		return 0;
	}
	while (cur->data == 0) {
		cur = cur->next;
		if (cur->next = NULL)
			return k;
	}
	while (cur != NULL) {
		k = k * 10 + cur->data;
		cur = cur->next;
	}
	return k;
}
Node* representInt(int m) {
	Node* haha = new Node;
	Node* temp = haha;
	int k = m, count=1;
	int sodu;
	if (haha == NULL)
		return NULL;
	if (m == 0)
		return NULL;
	while (k / 10 != 0) {
		k = k / 10;
		count++;
	}
	while (haha != NULL) {
		haha->data = m / pow(10, count-1);
		m = m - haha->data*pow(10, count-1);
		if (count != 1) {
			haha->next = new Node;
			haha = haha->next;
		}
		else {
			haha->next = NULL;
			haha = haha->next;
		}
		count--;
	}
	return temp;	
}
void output(Node* pH) {
	while (pH != NULL) {
		cout << pH->data << " ";
		pH = pH->next;
	}
	cout << endl;
}
