#pragma once
struct Node{
	int data;
	Node* next;
};
void input(Node* &pH);
void input2(Node* &pH1);
void output1(Node* pH);
void output2(Node* pH);
Node* reverse(Node* pH);
void removeEven(Node *&pH);
void removeall(Node *&pH);
void output3(Node *pH);
void input2(Node* &pH1);
Node* insertSome(Node* &pH);
void joinNode(Node* pH1, Node* pH2);
bool checkLoop(Node *pH1);
void output4(Node *pH);