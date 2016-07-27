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
	cout << temp->data;
	if (pHead->pNext != NULL)
		pHead = pHead->pNext;
	else pHead = NULL;
	delete temp;
}
int Stack::popspecial2() {
	int sum = 0;
	int k = 0;
	while (pHead != NULL) {
		sum += pHead->data*pow(16, k);
		pHead = pHead->pNext;
		k++;
	}
	return sum;
}
int Stack::popspecial() {
	int sum=0;
	int k = 0;
	while (pHead != NULL) {
		sum += pHead->data*pow(2,k);
		pHead = pHead->pNext;
		k++;
	}
	return sum;
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
		int count = 0;
		Node* cur = pHead;
		while (cur != NULL) {
			count++;
			cur = cur->pNext;
		}
		return count;
	}
}
void dec2bin(int a) {
	int du = 1, thuong = 1;
	Stack test;
	if (a == 0) {
		return ;
	}
	while (thuong != 0) {
		du = a % 2;
		test.push(du);
		thuong = a / 2;
		a = thuong;
	}
	while (test.numberOfElements() !=0) {
		test.pop();
	}
}
void bin2dec() {
	cout << " Input the number you want by each element: \n input a number other than 0 or 1 will stop the inputing ";
	Stack test;	
	int b;
	cin >> b;
	while (b==0 || b==1) {
		test.push(b);
		cout << " Go on! ";
		cin >> b;
	}
	cout<< "bin to dec: " << test.popspecial();

}
void dec2hex(int a) {
	int du = 1, thuong = 1;
	Stack test;
	if (a == 0) {
		return;
	}
	while (thuong != 0) {
		du = a % 16;
		test.push(du);
		thuong = a / 16;
		a = thuong;
	}
	while (test.numberOfElements() != 0) {
		test.pop();
	}
}
void hex2dec() {
	cout << " Input the number you want by each element: \n input a number other than 0 or 1 will stop the inputing ";
	Stack test;
	int b;
	cin >> b;
	while (b == 0 || b == 1) {
		test.push(b);
		cout << " Go on! ";
		cin >> b;
	}
	cout << "bin to dec: " << test.popspecial2();
}