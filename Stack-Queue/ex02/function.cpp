#include "function.h"
#include <iostream>
using namespace std;

Queue::Queue(void) {
	pHead = NULL;
	pTail = NULL;
}
void Queue::Enqueue(int t) {
	if (pTail != NULL) {
		pTail->pNext = new Node;
		pTail->pNext->data = t;
		pTail->pNext->pNext = NULL;
		pTail = pTail->pNext;
	}
	else{
		pHead = new Node;
		pHead->data = t;
		pHead->pNext = NULL;
		pTail = pHead;
	}
}
void Queue::Dequeue() {
	Node* temp = pHead;
	if (checkEmpty()) {
		cout << " Nothing to printout!";
	}
	else {
		Node* temp = pHead;
		cout << " Node dequeued : " << temp->data;
		if (pHead == pTail) {
			pTail = NULL;
			pHead = NULL;
		}
		else pHead = pHead->pNext;
		delete temp;
	}
}
bool Queue::checkEmpty() {
	if (pHead == NULL) {
		return true;
	}
	else return false;
}
void Queue::makeEmpty() {
	if (checkEmpty()) {
		cout << " Nothing to empty! \n";
	}
	else {
		Node* temp = pHead;
		while (pHead != NULL) {
			if (pHead == pTail) {
				pHead = NULL;
				pTail = NULL;
				delete temp;
			}
			else {
				pHead = pHead->pNext;
				delete temp;
			}
		}
	}
}
int Queue::numberOfElements(){
	if (checkEmpty())
		return 0;
	else {
		int count = 0;
		Node* cur = pHead;
		while (cur != NULL) {
			count++;
			cur = cur->pNext;
		}
		return count;
	}
}