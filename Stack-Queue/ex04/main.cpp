#include "function.h"
#include <iostream>
using namespace std;
int main() {
	Stack a;
	int dodai = 0;
	cout << " Please enter your expression: ";
	char input[100];
	cin.get(input,100,'\n');
	char result[100];
	Transform(input,result, a, dodai);
	cout << " Result : " << calculate(result, dodai);
	system("pause");


}