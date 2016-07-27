#include "function.h"
#include <fstream>
#include<iostream>
#include<string>
using namespace std;
studentlist::studentlist(void) {
	pH = NULL;
}
void studentlist::input(ifstream &fin, int m) {
	int n, dice;
	int count = 0;
	string f;
	if (fin) {
		fin >> n;
		fin.get();
		getline(fin, f);
		count++;
		student* cur = new student;
		if ((cur != NULL) && (!fin.eof())) {
			pH = cur;
			cur->ID = n;
			cur->name = f;
			cur->next = NULL;
		}
		while (count!= m*2-3) {
			fin >> n;
			fin.get();
			getline(fin, f);
			count++;
			cur->next = new student;
			if (cur->next != NULL) {
				cur = cur->next;
				cur->ID= n;
				cur->name = f;
				cur->next = NULL;
			}
		}
		cur->next = pH; //circular linked list
	}
	else cout << " cannot open file";
}
void studentlist::deleteStudent(int k) {
	student* cur = pH;
	int pos = 0;
	if (pH == NULL) {
		cout << " No student plays the game!";
		return;
	}
	if (pH->next == NULL) {
		cout << " No way, only 1 student play this game?";
		return;
	}
	while (cur!=NULL && cur->next!=NULL) {
		if (pos != k-1) {
			pos++;
			cur = cur->next;
		}
		else {
			student* temp = cur->next;
			if (temp->next == cur) {
				delete temp;
				cur->next = NULL;
				break;
			}
			else {
				cur->next = temp->next;
				delete temp;
				break;
			}
		}
	}
}
void studentlist::output() {
	ofstream out;
	out.open("outputfile.txt");
	out << pH->ID << " " << pH->name;
	out.close();
}
studentlist::~studentlist() {
	while (pH != NULL) {
		student* temp = pH;
		pH = pH->next;
		delete temp;
	}
}