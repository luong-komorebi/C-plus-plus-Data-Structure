#include "function.h"
#include <iostream>
using namespace std;


int main() {
	cout << " Welcome to my bookstore!\n";
	Book* pH;
	int k;
	char ISBN[11];
	char Name[201];
	initialize(pH);
	addABook(pH);
	cout << " Enter the ISBN of the book you want to buy: ";
	cin.get();
	cin.getline(ISBN, 11);
	sellABook(pH, ISBN);
	cout << " enter the name of the book you want to search: ";
	cin.get();
	cin.getline(Name, 201);
	findSub(Name, pH);
	cout << " Insert threshold: ";
	cin >> k;
	remK(pH, k);
	cout << " Books deleted!";
	return 0;

}