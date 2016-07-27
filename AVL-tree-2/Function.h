#pragma once

struct node {
	int key;
	node* left;
	node* right;
	int height;
};
class AVLtree {
public:
	node* root;
	AVLtree();
	node* rotateLeft(node* x);
	node* rotateRight(node* y);
	node* insert(node* N, int data);
	int getHeight(node *N);
	int checkBalance(node* N);
	void printPreorder(node* N);
	void printPostorder(node* N);
	void printInorder(node* N);
	node* Delete(node* N, int key);
	node* findSmallestRightNode(node* N);
};
int max(int a, int b);