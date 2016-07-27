//vo tran thanh luong
//1551020
//Week04
#include "function.h"
#include <iostream>
#include <fstream>
using namespace std;

void main() {
	cout << " Welcome to my program \n This program helps you reverse linked list \n";
	Node *pH;
	pH = NULL;
	input(pH);
	Node*k = reverse(pH);
	output1(k);
	removeEven(k);
	output2(k);
	Node*mk = insertSome(k);
	output3(mk);
	Node *pH1;
	pH1 = NULL;
	input(pH1);
	Node* pH2;
	pH2 = NULL;
	input2(pH2);
	joinNode(pH1, pH2);
	checkLoop(pH1);
	output4(pH);

}



	

