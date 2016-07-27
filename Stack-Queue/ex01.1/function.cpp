#include<iostream>
#include "function.h"
using namespace std;
Stack::Stack(void) {
	top = -1;
	size = 0;
	data = NULL;
}
void Stack::makeStack(int m) {
	top = -1;
	size = m;
	data = new int[size];
}
bool Stack::empty() {
	if (top == -1)
		return true;
	else return false;
}
void Stack::push(int t) {
	if (top == size - 1) // stack is full
		cout << " Stack is full";
	else {
		data[++top] = t;
	}
}
int Stack::pop() {
	if (empty()) {
		cout << " Stack is empty!";
	}
	else {
		return data[top--];
	}
}
void Stack::makeEmpty() {
	if (empty())
		cout << " Nothing to make empty!";
	else {
		delete[] data;
		top = -1;
		size = 0;
	}
}
int Stack::numberOfElements() {
	if (empty())
		return 0;
	else {
		return top;
	}
}
