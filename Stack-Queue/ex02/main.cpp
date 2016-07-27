#include <iostream>
#include "function.h"
using namespace std;
int main() {
	cout << " Welcome to my queue! \n";
	int n, GetOut;
	char answer;
	Queue a;
	cout << " Enter the number you want to add to queue!\n Enter 0 to stop!" << endl;
	cin >> n;
	while (n != 0) {
		a.Enqueue(n);
		cin >> n;
	}
	cout << " There are " << a.numberOfElements() << " elements in the queue!" << endl;
	cout << " How many elements you want to get out" << endl;
	cin >> GetOut;
	for (int i = 0; i < GetOut; i++) {
		a.Dequeue();
		cout << endl;
	}
	cout << " Do you want to make the queue empty? ( Y/N)";
	cin >> answer;
	if (answer == 'Y') {
		a.makeEmpty();
		cout << " The queue is now empty!!\n";
	}
	cout << " THank you! Have a nice day\n";
	system("pause");
}