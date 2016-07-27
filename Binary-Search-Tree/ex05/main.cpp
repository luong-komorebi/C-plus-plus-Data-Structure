#include "function.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
	SearchTree tree;
	ifstream in;
	ofstream out;
	string a, b;
	string inputToSearch;
	int choice;
	in.open("emtional-dictionary.txt");
	while (!in.eof()) {
		in >> a;
		in.ignore();
		getline(in, b, '\n');
		tree.insert(a, b);
	}
	in.close();
	cout << " Please choose 0 or 1  : \n 0: Search by Key \n 1: Search by content\n ";
	cin >> choice;
	cin.ignore();
	cout << " Input key / content: ";
	getline(cin, inputToSearch);
	cout << "====== Search done! If you see nothing, the thing you search doesnt exist!" << endl;
	cout << tree.search(inputToSearch, choice) << endl;
	system("pause");
}