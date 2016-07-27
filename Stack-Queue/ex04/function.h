#pragma once

struct Node {
	char data;
	Node* pNext;
};
class Stack {
private: Node*  pHead;
public: Stack();
		void push(char t);
		char pop();
		bool Empty();
		void makeEmpty();
		int numberOfElements();
		char top();
};
class Stackint {
private: Node*  pHead;
public: Stackint();
		void push(int t);
		int pop();
		bool Empty();
		void makeEmpty();
		int numberOfElements();
		int top();
};
int sortPriority(char a);
void Transform(char input[], char result[], Stack a, int &dodai);
int pheptinh(int a1, int a2, char c);
int calculate(char result[], int dodai);

