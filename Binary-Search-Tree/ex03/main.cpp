#include "function.h"
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
	fileout.open("out.txt");
	tree.printout(tree.root, fileout);
	fileout.close();
}