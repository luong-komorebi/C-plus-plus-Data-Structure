#include "btree.h"
#include <fstream>
#include <iostream>
using namespace std;
int main() {
	ifstream file;
	ofstream fileout;
	int a;
	Btree tree;
	file.open("input.txt");
	while (!file.eof()) {
		file >> a;
		tree.insert(a, tree.root);	
	}
	file.close();
	fileout.open("out1.txt");
	tree.printoutPreorder(tree.root,fileout);
	fileout.close();
	fileout.open("out2.txt");
	tree.printoutPostorder(tree.root,fileout);
	fileout.close();
	

}