// Vo Tran Thanh Luong
//1551020
// Week 06

#include "Function.h"
#include <iostream>
using namespace std;
int main() {
	AVLtree tree;
	int x, xdelete;
	tree.root = tree.insert(tree.root, 10);
	tree.root = tree.insert(tree.root, 20);
	tree.root = tree.insert(tree.root, 5);
	tree.root = tree.insert(tree.root, 40);
	tree.root = tree.insert(tree.root, 30);
	tree.root = tree.insert(tree.root, 60);
	tree.root = tree.insert(tree.root, 25);
	tree.root = tree.insert(tree.root, 1);
	cout << "I have already inserted some numbers(10,20,5,40,30,60,25,1).\nHowever, let's take 1 input from you: ";
	cin >> x;
	tree.root = tree.insert(tree.root, x);
	cout << " Input a number to delete : ";
	cin >> xdelete;
	tree.Delete(tree.root, xdelete);
	cout << "Print Pre order: (value/height) " << endl;
	tree.printPreorder(tree.root);
	cout << endl;
	cout << "Print In order:  (value/height) " << endl;
	tree.printInorder(tree.root);
	cout << endl;
	cout << "Print Post order:  (value/height) " << endl;
	tree.printPostorder(tree.root);
	cout << endl;
	system("pause");
	return 0;
}