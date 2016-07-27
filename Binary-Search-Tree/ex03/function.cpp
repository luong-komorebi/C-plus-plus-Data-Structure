#include "function.h"
#include <fstream>
#include <iostream>
using namespace std;

Btree::Btree(void) {
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
		root->occurrence = 1;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (root->key_value < key) {
		insert(key, root->right);
	}
	else if (root->key_value == key) {
		root->occurrence += 1;
	}
	else insert(key, root->left);
}
void Btree::printout(node* &leaf, ofstream &fileout) {
	if (leaf == NULL) {
		return;
	}
	fileout << leaf->key_value << "  occurs  " << leaf->occurrence << "\n";
	printout(leaf->left, fileout);
	printout(leaf->right, fileout);
}
