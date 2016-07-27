#pragma once
#include <fstream>
#include<iostream>
using namespace std;
struct node {
	int key_value;
	node* left;
	node* right;
};
class Btree {

	
public:
	Btree();
	node* root;
	~Btree();
	void insert(int key, node* &root);
	void printoutPreorder(node* &leaf, ofstream &fileout);
	void printoutPostorder(node* &leaf, ofstream &fileout);
	void destroy_tree(node* leaf);
};