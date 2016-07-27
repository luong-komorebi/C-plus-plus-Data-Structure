#pragma once
struct Node {
	int data;
	Node *pPrev;
	Node *pNext;
};

class DLinkedList {
private: Node *pHead;
		 Node* pTail;
public: DLinkedList();
		void input();
		void PrintOutTheList();
		void FindX(int x);
		void Add2TheBeginning(int x);
		void Add2TheEnd(int x);
		void AddYbeforeX(int x, int y);
		void DeleteThe1stNode();
		void DeleteTheLastNode();
		void DeleteAllX(int x);
		~DLinkedList();
};
