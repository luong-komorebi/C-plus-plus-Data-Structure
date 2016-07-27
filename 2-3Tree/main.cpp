// Vo Tran Thanh Luong
// 1551020 
// Week 04
#include "function.h"
#include <iostream>
using namespace std;
int main()
{
	Btree t(3); 
	t.insert(12);
	t.insert(21);
	t.insert(7);
	t.insert(8);
	t.insert(14);
	t.insert(35);
	t.insert(9);
	t.insert(18);
	cout << "Tree output : \n";
	t.traverse();
	cout << endl;
	cout << "Height : " << t.getHeight() <<endl;
	cout << "Min : " << t.getMin() << endl;
	cout << "Max : " << t.getMax() << endl;
	cout << "Width : " << t.getWidth() << endl;
	system("pause");
	return 0;
}