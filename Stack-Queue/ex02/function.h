#pragma once
struct Node {
	int data;
	Node* pNext;
};
class Queue {
private: Node* pHead;
		 Node* pTail;
public:
	Queue();
	void Enqueue(int t);
	void Dequeue();
	bool checkEmpty();
	void makeEmpty();
	int numberOfElements();
};