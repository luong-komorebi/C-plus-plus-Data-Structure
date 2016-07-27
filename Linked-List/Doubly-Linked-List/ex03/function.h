#pragma once
#include <fstream>
using namespace std;
struct number{
	int data;
	number* next;
	number* prev;
};
class numberlist{
public:
	number* pH;
	number* pT;
	numberlist();
	void input(ifstream &fin);
	void output();
};
void add2(numberlist one , numberlist two);
void substract2(numberlist one, numberlist two);
void multiply2(numberlist one, numberlist two);
number* smallMutilply(number* cur1, number* cur2);
void add2node(number* m, number* k);
void addzero(number* k, int i);
void outputform(number* pH);
void divide2(numberlist one , numberlist two);
bool sosanh(numberlist one, numberlist two);