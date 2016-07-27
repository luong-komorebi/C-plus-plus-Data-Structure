#include "Function.h"
#include <iostream>
using namespace std;

AVLtree::AVLtree() {
	root = NULL;
}
int AVLtree::getHeight(node* N) {
	if (N == NULL) {
		return 0;
	}
	return N->height;
}
node* AVLtree::rotateLeft(node* x) {
	node* y = x->right;
	node* z = y->left;
	y->left = x;
	x->right = z;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	return y;
}
node* AVLtree::rotateRight(node* x) {
	node* y = x->left;
	node* z = y->right;
	y->right = x;
	x->left = z;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	return y;
}
int AVLtree::checkBalance(node* N) {
	if (N == NULL) {
		return 0;
	}
	return getHeight(N->left) - getHeight(N->right);
}
node* AVLtree::insert(node* N, int data) {
	if (N == NULL) {
		N = new node;
		N->key = data;
		N->left = NULL;
		N->right = NULL;
		N->height = 1;
		return N;
	}
	if (data < N->key) {
		N->left = insert(N->left, data);
	}
	else N->right = insert(N->right, data);
	N->height = max(getHeight(N->left), getHeight(N->right)) + 1;
	int balance = checkBalance(N);
	if (balance > 1 && data < N->left->key) {
		return rotateRight(N);
	}
	if (balance < -1 && data > N->right->key) {
		return rotateLeft(N);
	}
	if (balance > 1 && data > N->right->key) {
		N->left = rotateLeft(N->left);
		return rotateRight(N);
	}
	if (balance < -1 && data < N->right->key) {
		N->right = rotateRight(N->right);
		return rotateLeft(N);
	}
	return N;
}
int max(int a, int b) {
	return ((a > b) ? a : b);
}
void AVLtree::printPreorder(node* N) {
	if (N != NULL) {
		cout << N->key << "/" << N->height << "    ";
		printPreorder(N->left);
		printPreorder(N->right);
	}
}
void AVLtree::printInorder(node* N) {
	if (N != NULL) {
		printInorder(N->left);
		cout << N->key << "/" << N->height << "    ";
		printInorder(N->right);
	}
}
void AVLtree::printPostorder(node* N) {
	if (N != NULL) {
		printPostorder(N->left);
		printPostorder(N->right);
		cout << N->key << "/" << N->height << "    ";
	}
}
node* AVLtree::Delete(node* N, int key) {
	if (N == NULL) {
		return N;
	}
	if (key < N->key) {
		N->left = Delete(N->left, key);
	}
	else if (key > N->key) {
		N->right = Delete(N->right, key);
	}
	else { // 1 con hoac 0 con
		if (N->left == NULL || N->right == NULL) {
			node* temp = NULL;
			if (N->left == NULL) {
				temp = N->right;
			}
			else if (N->right == NULL) {
				temp = N->left;
			}
			else temp = NULL;
			if (temp == NULL) { // 0 con
				temp = N;
				N = NULL;
			}
			else {
				N->key = temp->key; // 1 con
				N->height = temp->height;
				N->left = temp->left;
				N->right = temp->right;
			}
			delete temp;
		}
		else { // 2 con
			node* temp = findSmallestRightNode(N->right);
			N->key = temp->key;
			N->right = Delete(N->right, temp->key);
		}
	}
	if (N == NULL) { // nguyen cay chi co 1 node
		return N;
	}
	N->height = max(getHeight(N->left), getHeight(N->right)) + 1;
	int balance = checkBalance(N);
	if (balance > 1 && checkBalance(N->left) >= 0) {
		return rotateRight(N);
	}
	if (balance < -1 && checkBalance(N->right) <= 0) {
		return rotateLeft(N);
	}
	if (balance > 1 && checkBalance(N->left) < 0) {
		N->left = rotateLeft(N->left);
		return rotateRight(N);
	}
	if (balance < -1 && checkBalance(N->right) >0) {
		N->right = rotateRight(N->right);
		return rotateLeft(N);
	}
	return N;
}

node* AVLtree::findSmallestRightNode(node* N) {
	node* current = N;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}