#pragma once
#include <iostream>
using namespace std;

class node {
	int *data;
	int t; //t = maximum number of nodes
	node ** child;
	int n; // current number of nodes
	bool leaf;
public:
	node(int t1, bool leaf1);
	void insert(int k); // only insert when not full
	void splitChild(int i, node* temp);
	void traverse();
	int getHeight(int a);
	int getMin();
	int getMax();
	int getWidth();
friend class Btree;
};
class Btree {
	node* root;
	int t;
public:
	Btree(int t1);
	void traverse();
	void insert(int k);
	int getHeight();
	int getMin();
	int getMax();
	int getWidth();
};