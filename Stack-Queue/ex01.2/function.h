#pragma once
struct Node {
	int data;
	Node* pNext;
};
class Stack{
private: Node*  pHead;
public: Stack();
		void push(int t);
		void pop();
		bool Empty();
		void makeEmpty();
		int numberOfElements();
};