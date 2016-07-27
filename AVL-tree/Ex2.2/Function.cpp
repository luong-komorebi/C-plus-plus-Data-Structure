#include "Function.h"
#include <iostream>
#include <string>
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
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
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
node* AVLtree::insert(node* N, int data, string gender) {
	if (N == NULL) {
		N = new node;
		N->key = data;
		N->gender = gender;
		N->left = NULL;
		N->right = NULL;
		N->height = 1;
		return N;
	}
	if (data < N->key) {
		N->left = insert(N->left, data, gender);
	}
	else N->right = insert(N->right, data, gender);
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
void AVLtree::Update(node* N, int ID) {
	if (N->key == ID) {
		string gender;
		cin.ignore();
		cout << "Please update the gender : ";
		getline(cin, gender);
		cout << "Updated" << endl;
		return;
	}
	else if (N->key < ID) {
		Update(N->right, ID);
	}
	else Update(N->left, ID);
}
void AVLtree::Count(node* N, int &male, int &female) {
	if (N == NULL) {
		return;
	}
	if (N->gender.compare("male") == 0)
		male++;
	else female++;
	Count(N->left, male, female);
	Count(N->right, male, female);
}
int AVLtree::findDiff(node*N, int ID) {
	if (N->key < ID || N->key == ID) {
		int male = 0, female = 0;
		Count(N, male, female);
		return (abs(male - female));
	}
	else if (N->key > ID)
		return findDiff(N->left, ID);
}