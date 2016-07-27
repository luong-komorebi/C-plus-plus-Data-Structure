#pragma once
struct Node {
	int data;
	Node* pNext;
};
class Stack {
private: Node*  pHead;
public: Stack();
		void push(int t);
		void pop();
		int popspecial();
		bool Empty();
		void makeEmpty();
		int numberOfElements();
		int popspecial2();
};
void dec2bin(int a);
void bin2dec();
void dec2hex(int a);
void hex2dec();
