#include "function.h"
#include <iostream>
using namespace std;
Stack::Stack(void) {
	pHead = NULL;
}
void Stack::push(char t) {
	Node* temp = new Node;
	if (temp == NULL) {
		cout << " Memory is full!";
	}
	temp->data = t;
	temp->pNext = pHead;
	pHead = temp;
}
char Stack::pop() {
	char output;
	if (Empty()) {
		return NULL;
	}
	Node* temp;
	temp = pHead;
	output = temp->data;
	if (pHead->pNext != NULL)
		pHead = pHead->pNext;
	else pHead = NULL;
	delete temp;
	return output;
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
char Stack::top() {
	if (Empty()) {
		return NULL;
	}
	else {
		Node* cur = pHead;
		return cur->data;
	}
}
Stackint::Stackint(void) {
	pHead = NULL;
}
void Stackint::push(int t) {
	Node* temp = new Node;
	if (temp == NULL) {
		cout << " Memory is full!";
	}
	temp->data = t;
	temp->pNext = pHead;
	pHead = temp;
}
int Stackint::pop() {
	int output;
	if (Empty()) {
		return NULL;
	}
	Node* temp;
	temp = pHead;
	output = temp->data;
	if (pHead->pNext != NULL)
		pHead = pHead->pNext;
	else pHead = NULL;
	delete temp;
	return output;
}
bool Stackint::Empty() {
	if (pHead == NULL)
		return true;
	else return false;
}
void Stackint::makeEmpty() {
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
int Stackint::numberOfElements() {
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
int Stackint::top() {
	if (Empty()) {
		return NULL;
	}
	else {
		Node* cur = pHead;
		return cur->data;
	}
}
int sortPriority(char a) {
	if ( a == '*' ||  a == '/') {
		return 2;
	}
	else if ( a =='-' || a == '+') {
		return 1;
	}
	return 0;
}
void Transform(char input[], char result[], Stack a, int &dodai) {
	int i = 0, j=0;
	while (input[i] != '\0' ) {
		if (input[i] >= 48 && input[i] <= 57) {
			result[j] = input[i];
			j++;
			i++;
			continue;
		}
		else if (input[i] == '(') {
			a.push(input[i]);
			i++;
			continue;
		}
		else if (input[i] == ')') {
			while (a.pop() != '(') {
				result[j] = a.pop();
				j++;
			}
			i++;
			continue;
		}
		else {
			if (sortPriority(input[i]) > sortPriority(a.top())) {
				a.push(input[i]);
				i++;
				continue;
			}
			else {
				result[j] = a.pop();
				a.push(input[i]);
				j++;
				i++;
				continue;
			}
		}
	}
	while (!(a.Empty())) {
		result[j] = a.pop();
		j++;	
	}
	dodai = j;
}
int chartoint(char m) {
	switch (m) {
	case 48:
		return 0;
	case 49:
		return 1;
	case 50:
		return 2;
	case 51: 
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 54:
		return 6;
	case 55:
		return 7;
	case 56:
		return 8;
	default:
		return 9;
	}
}

int pheptinh(int a1, int a2, char c) {

	switch (c) {
	case '+':
		return a1 + a2;
	case '-':
		return a2-a1;
	case '*':
		return a1*a2;
	case '/':
		return a1 / a2;
	}
}

int calculate(char result[], int dodai) {
	Stackint temp;
	int i = 0, a1,a2;
	while (i < dodai) {
		if (result[i] >= 48 && result[i] <= 57) {
			temp.push(result[i] - 48);
		}
		if (result[i] == '+' || result[i] == '-' || result[i] == '*' || result[i] == '/') {
			a1 = temp.pop();
			a2 = temp.pop();
			temp.push(pheptinh(a1, a2, result[i]));
		}
		i++;
	}
	return temp.top();

}