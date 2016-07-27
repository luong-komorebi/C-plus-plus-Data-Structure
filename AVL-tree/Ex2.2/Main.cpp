// Vo Tran Thanh Luong
//1551020
// Week 05


// I propose using AVL TREE for msThao requirements !!



#include <string>
#include "Function.h"
#include <iostream>
using namespace std;
int main() {
	AVLtree tree;
	int x, ID;
	string gender;
	cout << "For simplicity(to save input time), I only include 2 info : ID and Gender\nOther info can be added easily, though!\n";
	tree.root = tree.insert(tree.root, 1551001, "male");
	tree.root = tree.insert(tree.root, 1551032, "male");
	tree.root = tree.insert(tree.root, 1551013, "female");
	tree.root = tree.insert(tree.root, 1551041, "male");
	tree.root = tree.insert(tree.root, 1551001, "male");
	tree.root = tree.insert(tree.root, 1551011, "female");
	tree.root = tree.insert(tree.root, 1551065, "female");
	tree.root = tree.insert(tree.root, 1551042, "female");
	cout << "I have already inserted some students {\n1551001 : male,\n1551032 : male,\n1551013 : female,\n1551041 : male,\n1551001 : male,\n1551011 : female,\n1551065 : female,\n1551042 : female\n}.\nHowever, let's take 1 input from you:\n ";
	cout << "Student ID: ";
	cin >> x;
	cin.ignore();
	cout << "Student Gender: (male/female) ";
	getline(cin, gender);
	tree.root = tree.insert(tree.root, x, gender);
	cout << "Input the desire ID (15510xx) to update info\n";
	cin >> ID;
	tree.Update(tree.root, ID);
	cout << "Input the desire ID (15510xx) to find the difference\n between the number of girls and the number of boys\n among all the students with id smaller than k : ";
	cin >> ID;
	cout << " Difference is : \n" << tree.findDiff(tree.root, ID);
	system("pause");
	return 0;
}