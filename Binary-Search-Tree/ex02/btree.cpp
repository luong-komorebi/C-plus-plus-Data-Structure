#include "btree.h"
#include <fstream>
#include <iostream>
using namespace std;

Btree::Btree(void ) {
	root = NULL;
}
Btree::~Btree() {
	destroy_tree(root);
}
void Btree::destroy_tree(node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}
void Btree::insert(int key, node*& root) {
	if (root == NULL) {
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (root->key_value < key) {
		insert(key, root->right);
	}
	else insert(key, root->left);
}
void Btree::printoutPreorder(node* &leaf, ofstream &fileout) {
	if (leaf == NULL) {
		return;
	}
	fileout << leaf->key_value << " ";
	printoutPreorder(leaf->left,fileout);
	printoutPreorder(leaf->right,fileout);
}
void Btree::printoutPostorder(node* &leaf, ofstream &fileout) {
	if (leaf == NULL) {
		return;
	}
	printoutPostorder(leaf->left, fileout);
	printoutPostorder(leaf->right, fileout);
	fileout << leaf->key_value << " ";
}
