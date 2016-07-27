#pragma once
#include <iostream>
using namespace std;

struct node {
	int key_value;
	int occurrence;
	node* left;
	node* right;
};
class Btree {


public:
	Btree();
	node* root;
	~Btree();
	void insert(int key, node* &root);
	void printout(node* &leaf, ofstream &fileout);
	void destroy_tree(node* leaf);
};