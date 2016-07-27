#include <iostream>
using namespace std;
#include "function.h"

int main() {
	Node* pH;
	pH = NULL;
	input(pH);
	cout << endl;
	int n,m;
	cout << " insert the data you wanna input : ";
	cin >> n;
	Node* k = insertNew(pH, n);
	cout << " 1.    ";
	output(k);
	Node* a = inOut(pH);
	cout << " 2.   ";
	output(a);
	Node *pH2;
	pH2 = NULL;
	rearrange(pH, pH2);
	Node* pH3;
	pH3 = NULL;
	input2(pH3);
	Node* b = combine(pH, pH3);
	cout << "4.    ";
	output(b);
	input(pH);
	input2(pH3);
	Node* c = joining(pH, pH3);
	cout << " 5.   ";
	output(c);
	input(pH);
	int d = computeintoInteger(pH);
	cout << " 6.  " << d << endl;
	cout << " enter the integr you want to represent: ";
	cin >> m;
	cout << " 7.  ";
	Node* e = representInt(m);
	output(e);


}