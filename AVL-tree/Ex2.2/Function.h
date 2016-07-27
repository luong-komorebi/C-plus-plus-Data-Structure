#pragma once
#include <string>
using namespace std;


struct node {
	int key;
	string gender;
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
	node* insert(node* N, int data, string gender);
	int getHeight(node *N);
	int checkBalance(node* N);
	void Count(node* N, int &male, int &female);
	int findDiff(node*N, int ID);
	void Update(node* N, int ID);
};
int max(int a, int b);