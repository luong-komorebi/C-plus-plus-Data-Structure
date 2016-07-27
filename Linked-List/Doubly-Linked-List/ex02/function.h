#pragma once
#include <string>
#include <fstream>
using namespace std;
struct student{
	int ID;
	string name;
	student* next;
};
class studentlist {
private: student* pH;
public: studentlist();
		void input(ifstream &fin, int m);
		void deleteStudent(int k);
		void output();
		~studentlist();
};