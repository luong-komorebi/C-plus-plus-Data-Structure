#include "function.h"
#include <iostream>
using namespace std;
int main() {
	int n, a;
	cout << " Welcome to my program!\n";
	cout << "1. Decimal->binary\n2. Binary->decimal\n3.Decimal->hex\n4.Hex->decimal\n";
	cout << "Please input your choice!\n";
	cin >> n;
	switch (n) {
	case 1:
		cout << " Enter the number you want : ";
		cin >> a;
		cout << " Dec to bin: ";
		dec2bin(a);
		break;
	case 2:
		bin2dec();
		cout << " Bin to Dec: ";	
		break;
	case 3:
		cout << " Enter the number you want : ";
		cin >> a;
		cout << " Dec to hex: ";
		dec2hex(a);
		break;
	case 4:
		hex2dec();
		cout << " hex to dec: ";
		break;
		break;
	default:
		cout << " Input invalid! Please choose again!\n";
		cin >> n;
	}
	cout << endl;
	system("pause");
}