#include <iostream>
#include "function.h"
using namespace std;
int main() {
	cout << " Welcome to my queue! \n";
	int n, GetOut, size;
	char answer;
	Queue a;
	cout << " Enter the size of the queue: ";
	cin >> size;
	cout << " Enter the number you want to add to queue!" << endl;
	a.makeQueue(size);
	for (int g = 0; g < size; g++) {
		cin >> n;
		a.enqueue(n);	
	}
	cout << " There are " << a.numberOfElements() << " elements in the queue!" << endl;
	cout << " How many elements you want to get out" << endl;
	cin >> GetOut;
	for (int i = 0; i < GetOut; i++) {
		a.dequeue();
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