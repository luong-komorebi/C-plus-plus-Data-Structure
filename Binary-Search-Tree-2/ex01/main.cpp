//Vo tran thanh luong
//1551020

#include "function.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
	SearchTree tree;
	SearchTree FavoriteTree;
	ifstream in;
	ofstream out;
	string a, b,inputToSearch, inputToDelete, favoriteEmotion, favoriteEmotionDelete, favoriteEmotionEdit;
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
	cout << "====== Search done! If you see nothing, the thing you search doesnt exist!=====" << endl;
	cout << tree.search(inputToSearch, choice) << endl;
	cout << ".\n.\n.\n.\n.";
	cout << "Do you want to delete anything? (1 = yes , 0 = no)" << endl;
	cin >> choice;
	if (choice != 0 && choice != 1)
		cout << "====Game over! Restart your program and input 0/1 only====";
	cin.ignore();
	cout << "Input the emo you want to delete : " << endl;
	getline(cin, inputToDelete);
	tree.deleteData(inputToDelete);
	cout << "====Deleted!! You can search again to confirm !====";
	cout << "\n Please choose 0 or 1  : \n 0: Search by Key \n 1: Search by content\n ";
	cin >> choice;
	cin.ignore();
	cout << " Input key / content: ";
	getline(cin, inputToSearch);
	cout << "====== Search done! If you see nothing, the thing you search doesnt exist!=====" << endl;
	cout << tree.search(inputToSearch, choice) << endl;
	cout << ".\n.\n.\n.\n.";
	cout << " Do you want to make a favorite tree? (1: yes || 0:no) ";
	cin >> choice;
	if (choice != 0 && choice != 1)
		cout << "====Game over! Restart your program and input 0/1 only====";
	if (choice == 0) {
		cout << " BYE! ";
		return 0;
	}
	cout << " What do you want to do with your favorite tree ?\n 1: Add\n 2:Remove\n 3:Edit";
	cin >> choice;
	if (choice == 1) {
		while (choice == 1) {
			cin.ignore();
			cout << " Add your favorite emotion : ";
			getline(cin, favoriteEmotion);
			FavoriteTree.insert(favoriteEmotion, tree.search(favoriteEmotion, 0));
			cout << " Input 1 to keep adding more! Input 0 to exit! ";
			cin >> choice;
		}
	}
	else if (choice == 2) {
		while (choice == 2) {
			cin.ignore();
			cout << " Want to remove which one? : ";
			getline(cin, favoriteEmotionDelete);
			FavoriteTree.deleteData(favoriteEmotionDelete);
			cout << " Input 2 to keep adding more! Input 0 to exit! ";
			cin >> choice;
		}
	}
	else if (choice == 3) {
		while (choice == 2) {
			cin.ignore();
			cout << " Want to edit which one? : ";
			getline(cin, favoriteEmotionEdit);
			FavoriteTree.deleteData(favoriteEmotionEdit);
			cout << " input new meaning ";
			getline(cin, a);
			FavoriteTree.insert(favoriteEmotionEdit, a);
			cout << " Input 3 to keep adding more! Input 0 to exit! ";
			cin >> choice;
		}
	}
	else cout << "====Game over! Restart your program and input as instructed only====";
	cout << " Task done!   BYE!!!!";
	return 0;
	system("pause");
}