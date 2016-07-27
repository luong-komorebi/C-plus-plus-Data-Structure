#include <iostream>
#include "function.h"
using namespace std;
int main() {
	cout << " Welcome to my stack! \n";
	int n,GetOut;
	char answer;
	Stack a;
	cout << " Enter the number you want to add to stack!\n Enter 0 to stop!"<<endl;
	cin >> n;
	while (n != 0){
		a.push(n);
		cin >> n;	
	} 
	cout << " There are " << a.numberOfElements() << " elements in the stack!"<<endl;
	cout << " How many elements you want to get out"<<endl;
	cin >> GetOut;
	for (int i = 0; i < GetOut; i++) {
		a.pop();
		cout << endl;
	}
	cout << " Do you want to make the stack empty? ( Y/N)";
	cin >> answer;
	if (answer == 'Y') {
		a.makeEmpty();
		cout << " The stack is now empty!!\n";
	}
	cout << " THank you! Have a nice day\n";
	system("pause");
}