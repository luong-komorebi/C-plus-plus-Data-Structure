#include "function.h"
#include <iostream>
using namespace std;
int main() {
	cout << " Welcome to my program";
	DLinkedList a;
	int  b, c,x,d,f ,e ;
	a.input();
	a.PrintOutTheList();
	cout << " Please enter an integer you want to find : ";
	cin >> b;
	a.FindX(b);
	a.PrintOutTheList();
	cout << endl;
	cout << " Add an integer you want to insert at the beginning: ";
	cin >> c;
	a.Add2TheBeginning(c);
	a.PrintOutTheList();
	cout << endl;
	cout << " Add an integer you want to insert at the end: ";
	cin >> d;
	a.Add2TheEnd(d);
	a.PrintOutTheList();
	cout << endl;
	cout << " Add x: ";
	cin >> x;
	cout << " Add an integer you want to insert before x ";
	cin >> e;
	a.AddYbeforeX(e,x);
	a.PrintOutTheList();
	cout << endl;
	a.DeleteThe1stNode();
	cout << " 1st node deleted \n!";
	a.PrintOutTheList();
	cout << endl;
	a.DeleteTheLastNode();
	cout << " last node deleted \n!";
	a.PrintOutTheList();
	cout << endl;
	cout << " Add an integer you want to delete: ";
	cin >> f;
	a.DeleteAllX(f);
	a.PrintOutTheList();
	cout << endl;
}
	