// Please refer to the requiremnet.png file to see what i am doing here!


#include <iostream>
#include "function.h"
using namespace std;

void initialize(Book* &pH) {
	pH = NULL;
}
void addABook(Book* &pH) {
	int n;
	cout << " How many books?";
	cin >> n;
	Book* cur = new Book;
	pH = cur;
	for (int i = 0; i < n; i++) {
		if (cur == NULL)
			return;
		int check1 = 1;
		bool check= false;
		cout << "Input a new book\n\n";
		cout << "Title : ";
		cin.get();
		cin.getline(cur->title, 201);
		Book* temp = pH;
		while (temp != NULL && check1 !=1) {
			if (strcmp(temp->title, cur->title)==0) {
				temp->stock++;
				check = true;
				break;
			}
			temp = temp->next;
		}
		if (check == true) {
			cur->next = NULL;
			break;
		}
		cout << "ISBN : ";
		cin.getline(cur->isbn, 11);
		cout << "Author : ";
		cin.getline(cur->author, 41);	
		cout << "Language : ";
		cin.getline(cur->lang, 31);
		cout << "Year published: ";
		cin >> cur->year;
		cout << "Price: ";
		cin >> cur->dollars;
		cout << "Stock level: ";
		cin >> cur->stock;
		cin.get();
		check1++;
		if (i == n - 1) {
			cur->next = NULL;
		}
		else {
			cur->next = new Book;
			cur = cur->next;
		}
	}	
}
void sellABook(Book* pH, char ISBN[]) {
	Book* cur = pH;
	while ( cur!=NULL){
		if (strcmp(ISBN,cur->isbn ) == 0) {
			cout << " the book you want to buy is " << cur->title << endl;
			cout << " Price : " << cur->dollars << endl;
			if (cur->stock == 0) {
				cout << " OUT OF STOCK. We are sorry";
			}
			else {
				cout << " Buying is done ! \n";
				cur->stock--;
			}
			break;
		}
		cur = cur->next;
	}
	if (cur == NULL)
		cout << " we dont have the book you want." << endl;
}
void findSub(char Name[], Book* pH) {
	int count = 0;
	for (Book* a = pH; a != NULL; a = a->next) {
		char* b;
		b = strstr(a->title, Name);
		if (b != NULL) {
			count++;
			cout << "Found book " << count << endl;
			cout << "Title" << a->title << endl;
			cout << "ISBN" << a->isbn << endl;
		}
		if (count == 0)
			cout << "FOUND NONE" << endl;
	}
}
void removeBook(Book* &a) {
		Book* b;
		a = a->next;
		b = a;
		delete b;
}

void remK(Book* &pH, int k) {
	while (pH != NULL){
		if (pH->stock < k) {
			removeBook(pH);
		}
		else {
			Book* cur = pH;
			if (cur->next == NULL)
				return;
			if (cur->next->stock < k)
				removeBook(cur->next);

		}

	}
}
