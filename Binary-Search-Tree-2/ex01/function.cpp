#include "function.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

SearchTree::SearchTree() {
	root = NULL;
}
bool SearchTree::insertTree(node* &root, string emo, string meaning) {
	if (root == NULL) {
		root = new node;
		if (root == NULL) {
			return false;
		}
		root->emo = emo;
		root->meaning = meaning;
		root->left = NULL;
		root->right = NULL;
		return true;
	}
	if (integerValue(emo) > integerValue(root->emo)) {
		return insertTree(root->right, emo, meaning);
	}
	else if (integerValue(emo) < integerValue(root->emo)) {
		return insertTree(root->left, emo, meaning);
	}
	else {
		if (root->emo == emo) {
			root->meaning.append(" / ");
			root->meaning.append(meaning);
			return true;
		}
		else {
			emo.append("*");
			return insertTree(root->right, emo, meaning);
		}

	}
}
int SearchTree::integerValue(string a) {
	int result = 0;
	for (int i = 0; i < a.length(); i++) {
		char x = a.at(i);
		result += int(x);
	}
	return result;
}
void SearchTree::destroyTree(node* root) {
	if (root == NULL) {
		return;
	}
	destroyTree(root->right);
	destroyTree(root->left);
	delete root;
}
SearchTree::~SearchTree() {
	destroyTree(root);
}
string SearchTree::searchByKey(node* root, string emo) {
	if (root == NULL) {
		return "cannot find!";
	}
	if (integerValue(emo) == integerValue(root->emo)) {
		if (emo == root->emo) {
			return (root->emo + "\t" + root->meaning);
		}
		else {
			emo.append("*");
			return searchByKey(root->right, emo);
		}
	}
	else if (integerValue(emo) < integerValue(root->emo))
		return searchByKey(root->left, emo);
	else return searchByKey(root->right, emo);
}
string SearchTree::searchByContent(node* root, string meaning) {
	if (meaning.find(root->meaning, 0) == string::npos) {
		return (root->emo + "\t" + root->meaning);
	}
	else {
		return searchByContent(root->left, meaning);
		return searchByContent(root->right, meaning);
	}
	if (root == NULL) {
		return "";
	}
}
bool SearchTree::insert(string a, string b) {
	return insertTree(root, a, b);
}
string SearchTree::search(string a, int b) {
	if (b == 0) {
		return searchByKey(root, a);
	}
	else if (b == 1) {
		return searchByContent(root, a);
	}
	else return "Choose 0/1 only. Please restart the program!";
}
void SearchTree::deleteOneDataRight(node* &root, string emo) {
	if (root == NULL)
		return;
	if (integerValue(emo) > integerValue(root->emo)) {
		deleteOneDataRight(root->right, emo);
	}
	else if (integerValue(emo) < integerValue(root->emo)) {
		deleteOneDataRight(root->left, emo);
	}
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return;
		}
		else if (root->left != NULL && root->right != NULL) {
			root->emo = smallestRightNode(root->right)->emo;
			deleteOneDataRight(root->right, smallestRightNode(root->right)->emo);
		}
		else {
			node* a = root;
			if (root->right) {
				root = root->right;
			}
			else root = root->left;
			delete a;
		}
	}
}
node* SearchTree::smallestRightNode(node* root) {
	if (root->left != NULL) {
		return smallestRightNode(root->left);
	}
	else return root;
}
void SearchTree::deleteOneDataLeft(node* &root, string emo) {
	if (root == NULL)
		return;
	if (integerValue(emo) > integerValue(root->emo)) {
		deleteOneDataLeft(root->right, emo);
	}
	else if (integerValue(emo) < integerValue(root->emo)) {
		deleteOneDataLeft(root->left, emo);
	}
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return;
		}
		else if (root->left != NULL && root->right != NULL) {
			root->emo = biggestLeftNode(root->left)->emo;
			deleteOneDataLeft(root->left, biggestLeftNode(root->left)->emo);
		}
		else {
			node* a = root;
			if (root->right) {
				root = root->right;
			}
			else root = root->left;
			delete a;
		}
	}
}
node* SearchTree::biggestLeftNode(node* root) {
	if (root->right != NULL) {
		return biggestLeftNode(root->right);
	}
	else return root;
}
void SearchTree::deleteData(string emo) {
	deleteOneDataRight(root, emo);
}