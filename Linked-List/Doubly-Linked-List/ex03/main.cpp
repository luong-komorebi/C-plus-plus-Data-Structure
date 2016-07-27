#include "function.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin;
	numberlist one;
	numberlist two;
	fin.open("input.txt");
	one.input(fin);
	fin.close();
	fin.open("input2.txt");
	two.input(fin);
	fin.close();
	add2(one, two);
	one.output();
	cout <<"  is sum " << endl;
	fin.open("input.txt"); //reinput 
	one.input(fin);
	fin.close();
	substract2(one, two);
	one.output();
	cout << " is substraction " << endl;
	fin.open("input.txt"); //reinput 
	one.input(fin);
	fin.close();
	multiply2(one, two);
	cout << " is multiply " << endl;
	fin.open("input.txt"); //reinput 
	one.input(fin);
	fin.close();
	divide2(one, two);
	cout << " is division " << endl;
	return 0;
}