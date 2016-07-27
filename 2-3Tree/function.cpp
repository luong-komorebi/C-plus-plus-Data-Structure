#include "function.h"
#include <iostream>
using namespace std;

Btree::Btree(int t1) {
	t = t1;
	root = NULL;
}
void Btree::traverse() {
	if (root != NULL)
		root->traverse();
}
node::node(int t1, bool leaf1) {
	t = t1;
	leaf = leaf1;
	data = new int[t - 1];
	child = new node*[t];
	for (int i = 0; i < t; i++)
		child[i] = NULL;
	n = 0;
}
void node::traverse() {
	int i;
	for (i = 0; i < n; i++) {
		if (leaf == false) {
			child[i]->traverse();
		}
		cout << "  " << data[i];
	}
	if (leaf == false) {
		child[i]->traverse();
	}
}
void node::splitChild(int i, node* x) {
	node* anotherNode = new node(x->t, x->leaf);
	anotherNode->n = (t - 1)/2;
	for (int a = 0; a < (t-1)/2; a ++ ) {
		anotherNode->data[a] = x->data[a+(t+1)/2];
	}
	if (x->leaf == false) {
		for (int j = 0; j < (t+1)/2; j++) {
			anotherNode->child[j] = x->child[j+(t+1)/2];
		}
	}
	x->n = (t - 1)/2;
	for (int j = n; j >= i + 1; j--)
		child[j + 1] = child[j];
	child[i + 1] = anotherNode;
	for (int j = n - 1; j >= i; j--) {
		data[j + 1] = data[j];
	}
	data[i] = x->data[(t-1)/2];
	n = n + 1;
}
void Btree::insert(int k) {
	if (root == NULL) {
		root = new node(t, true);
		root->data[0] = k;
		root->n = 1;
	}
	else {
		if (root->n == t ) {
			node* temp = new node(t, false);
			temp->child[0] = root;
			temp->splitChild(0, root);
			int i = 0;
			if (temp->data[0] < k)
				i++;
			temp->child[i]->insert(k);
			root = temp;
		}
		else
			root->insert(k);
	}
}
void node::insert(int k) {
	int i = n - 1;
	if (leaf == true) {
		while (i >= 0 && data[i] > k) {
			data[i + 1] = data[i];
			i--;
		}
		data[i + 1] = k;
		n = n + 1;
	}
	else {
		while (i >= 0 && data[i] > k) {
			i--;
		}
		if (child[i + 1]->n == t) {
			splitChild(i + 1, child[i + 1]);
			if (data[i + 1] < k) {
				i++;
			}
		}
		child[i + 1]->insert(k);
	}
}
int Btree::getHeight() {
	if (root != NULL) {
		return root->getHeight(1);
	}
}
int node::getHeight(int a) {
	int count = a;
	int i = 0;
	if (leaf == false) {
		return child[i]->getHeight(++count);
	}
	else {
		return ++count;
	}
}
int Btree::getMin() {
	if (root != NULL) {
		return root->getMin();
	}
}
int node::getMin() {
	int i = 0;
	if (leaf == false) {
		return child[i]->getMin();
	}
	else {
		return data[0];
	}
}
int Btree::getMax() {
	if (root != NULL) {
		return root->getMax();
	}
}
int node::getMax() {
	int i = n;
	if (leaf == false) {
		return child[i]->getMax();
	}
	else {
		return data[n-1];
	}
}
int Btree::getWidth() {
	if (root != NULL) {
		return root->getWidth();
	}
}
int node::getWidth() {
	int count=1;
	if (leaf == false) {
		if (child[0]->leaf == true) {
			return n + 1;
		}
		else {
			for (int i = 0; i <= n + 1; i++) {
				count += child[i]->getWidth();
			}
			return count;
		}
	}
}