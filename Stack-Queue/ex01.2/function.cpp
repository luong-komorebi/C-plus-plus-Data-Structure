#include <iostream>
#include "function.h"
using namespace std;
Stack::Stack(void) {
	pHead = NULL;
}
void Stack::push(int t) {
	Node* temp = new Node;
	if (temp == NULL) {
		cout << " Memory is full!";
	}
	temp->data = t;
	temp->pNext = pHead;
	pHead = temp;
}
void Stack::pop() {
	if (Empty()) {
		cout << " The stack is empty!";
	}
	Node* temp;
	temp = pHead;
	cout << " Stack poped : " << temp->data;
	if( pHead->pNext!=NULL)
		pHead = pHead->pNext;
	else pHead = NULL;
	delete temp;
}
bool Stack::Empty() {
	if (pHead == NULL)
		return true;
	else return false;
}
void Stack::makeEmpty() {
	if (Empty())
		cout << " Nothing to make empty";
	else {
		while (pHead != NULL) {
			Node* temp;
			temp = pHead;
			pHead = pHead->pNext;
			delete temp;
		}
	}
}
int Stack::numberOfElements() {
	if (Empty())
		return 0;
	else {
		int count=0;
		Node* cur = pHead;
		while (cur != NULL) {
			count++;
			cur = cur->pNext;
		}
		return count;
	}
}