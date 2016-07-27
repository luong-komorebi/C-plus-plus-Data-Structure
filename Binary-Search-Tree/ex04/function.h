#pragma once
#include <string>
using namespace std;
struct node {
	string emo;
	string meaning;
	node* left;
	node* right;
};
class SearchTree {
public:
	SearchTree();
	~SearchTree();
	bool insert(string a,string b);
	bool insertTree(node* &root,string emo, string meaning);
	int integerValue(string a);
	void destroyTree(node* root);
	string search(string a, int b);
	string searchByKey(node* root, string emo);
	string searchByContent(node* root, string meaning);
private: 
	node* root;
};
