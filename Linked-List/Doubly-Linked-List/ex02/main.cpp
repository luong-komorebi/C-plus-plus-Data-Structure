#include "function.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin;
	fin.open("log.txt");
	int sostudent;
	fin >> sostudent;
	studentlist a;
	a.input(fin,sostudent);
	int k;
	fin >>k;
	while (sostudent != 1) {
		a.deleteStudent(k);
		sostudent--;
		fin >> k;
	}
	a.output();
	fin.close();
}