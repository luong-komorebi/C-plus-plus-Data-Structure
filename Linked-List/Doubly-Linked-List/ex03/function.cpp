#include "function.h"
#include <iostream>
#include <fstream>
using namespace std;

numberlist::numberlist(void) {
	pH = NULL;
	pT = NULL;
}
void numberlist::input(ifstream &fin) {
	int n;
	if (fin) {
		fin >> n;
		number* cur = new number;
		if ((cur != NULL) && (!fin.eof())) {
			pH = cur;
			cur->data = n;
			cur->next = NULL;
			cur->prev = NULL;
		}
		while (!fin.eof()) {
			fin >> n;
			cur->next = new number;
			if (cur->next != NULL) {
				cur->next->data = n;
				cur->next->next= NULL;
				cur->next->prev = cur;
				cur = cur->next;
			}
			else pT = cur;
		}
		pT = cur;
	}
	else cout << " cannot open file";
}
void numberlist::output() {
	number* cur = pH;
	if (pH == NULL) {
		cout << " Nothing to do here.";
		return;
	}
	cout << " ";
	while (cur != NULL) {
		cout << cur->data ;
		cur = cur->next;
	}
}
void add2(numberlist one, numberlist two) {
	number* cur1 = one.pT;
	number* cur2 = two.pT;
	if (cur1 == NULL || cur2 == NULL || (cur1 == NULL && cur2 == NULL))
		cout << " Nothing to do here.";
	int temp = 0;
	int remember = 0;
	while (cur1 != NULL && cur2 != NULL) {
		
		temp = cur1->data + cur2->data + remember;
		if (temp >= 10) {
			remember = temp / 10;
			temp = temp % 10;
		}
		one.pT->data = temp;
		cur1 = cur1->prev;
		cur2 = cur2->prev;
		if (cur1 != NULL) {
			one.pT = one.pT->prev;
		}
	}
	if (cur1 == NULL && cur2 != NULL){
		cur1->prev = cur2;
		while (cur1->prev != NULL) {
			cur1 = cur1->prev;
			cur1->next = one.pT;
			one.pT = cur1;
		}
	}
	else if (cur1 != NULL && cur2 == NULL) {
		while (cur1->prev != NULL){
			cur1 = cur1->prev;
			one.pT = cur1;
		}
	}
	else {
		if (remember != 0) {
			number* temporary = new number;
			if (remember != 0) {
				temporary->data = remember;
				temporary->prev = NULL;
				one.pT->prev = temporary;
				temporary->next = one.pT;
				one.pT = one.pT->prev;
			}
		}
	}
}
void substract2(numberlist one, numberlist two) {
	number* cur1 = one.pT;
	number* cur2 = two.pT;
	if (cur1 == NULL || cur2 == NULL || (cur1 == NULL && cur2 == NULL))
		cout << " Nothing to do here.";
	int temp = 0;
	bool check = true;
	int remember = 0;
	number* travel1 = one.pT;
	number* travel2 = two.pT;
	while (travel1->prev != NULL && travel2->prev != NULL) {
		travel1 = travel1->prev;
		travel2 = travel2->prev;
	}
	if (travel1->prev == NULL && travel2->prev != NULL) {
		cur1= two.pT;
		cur2 = one.pT;
		cout << "-";
	}
	else if (travel1->prev == NULL && travel2->prev == NULL) {
		while (true) {
			if (travel1->data > travel2->data) {
				cur1 = one.pT;
				cur2 = two.pT;
				break;
			}
			else if (travel1->data < travel2->data) {
				cur1 = two.pT;
				cur2 = one.pT;
				cout << "-";
				break;
			}
			else {
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}
	}
	else {
		cur1 = one.pT;
		cur2 = two.pT;
	}
	while (cur1 != NULL && cur2 != NULL) {
		if (cur1->data < cur2->data) {
			cur1->data = cur1->data + 10;
			check = true;
		}
		else check = false;
		temp = cur1->data - cur2->data - remember;
		if (check == true)
			remember = 1;
		else remember = 0;
		one.pT->data = temp;
		cur1 = cur1->prev;
		cur2 = cur2->prev;
		if (cur1 != NULL) {
			one.pT = one.pT->prev;
		}
	}
	if (cur2 == NULL && cur1!=NULL) {
		if (remember == 1) {
			cur1->data--;
		}
		one.pT->prev = cur1;
		cur1->next = one.pT;
		while (cur1 != NULL) {
			one.pT = cur1;
			cur1 = cur1->prev;		
		}
	}

}
void multiply2(numberlist one, numberlist two) {
	number* cur1 = one.pT;
	number* cur2 = two.pT;
	if (one.pT == NULL || two.pT == NULL) {
		cout << "Nothing to do here!";
	}
	number* m = new number;
	m->data = 0;
	m->prev = NULL;
	m->next = NULL;
	int counter = 0;
	while ( cur1->prev!=NULL){
		number* k=smallMutilply(cur1, cur2);
		addzero(k,counter);
		add2node(m, k);
		counter++;
		cur2 = two.pT;
		cur1 = cur1->prev;
	}
	outputform(m);
}
number* smallMutilply(number* cur1, number* cur2) {
	number* cur3 = new number;
	cur3->next = NULL;
	cur3->prev = NULL;
	int counter = 1;
	int remember = 0;
	int temp = 0;
	while (cur2->prev != NULL) {
		temp = cur2->data*cur1->data + remember;
		if (temp >= 10) {
			cur3->data = temp % 10;
			cur3->prev = new number;
			cur3->prev->next = cur3;
			remember = temp / 10;
		}
		else {
			cur3->data = temp;
			cur3->prev = new number;
			cur3->prev->next = cur3;
			remember = 0;
		}
		cur2 = cur2->prev;
		cur3 = cur3->prev;
	}
	temp = (cur2->data*cur1->data + remember);
	if (temp >= 10) {
		cur3->data = temp % 10;
		cur3->prev = new number;
		cur3->prev->data = temp / 10;
		cur3->prev->prev = NULL;
		cur3->prev->next = cur3;
	}
	else {
		cur3->data = temp;
		cur3->prev = NULL;
	}
	return cur3;

}
void addzero(number* k, int i) {
	while (k->next != NULL) {
		k = k->next;
	}
	for (int g = 0; g < i; g++) {
		k->next = new number;
		k->next->data = 0;
		k->next->prev = k;
		k->next->next = NULL;
		k = k->next;
	}
}
void add2node(number* m, number* k) {
	while (k->next != NULL) {
		k = k->next;
	}
	number* cur1 = m;
	number* cur2 = k;
	if (cur1 == NULL || cur2 == NULL || (cur1 == NULL && cur2 == NULL))
		cout << " Nothing to do here.";
	int temp = 0;
	int remember = 0;
	while (cur1 != NULL && cur2 != NULL) {

		temp = cur1->data + cur2->data + remember;
		if (temp >= 10) {
			remember = temp / 10;
			temp = temp % 10;
		}
		cur1->data = temp;
		if (cur1->prev == NULL ){
			break;
		}
		cur1 = cur1->prev;
		if (cur2->prev == NULL) {
			break;
		}
		cur2 = cur2->prev;
	}
	if (cur1->prev == NULL && cur2 != NULL) {
		cur1->prev = cur2->prev;
		while (cur1->prev != NULL) {
			cur1->prev->next = cur1;
			cur1 = cur1->prev;
		}
	}
	else if (cur1->prev != NULL && cur2->prev == NULL) {
		while (cur1->prev != NULL) {
			cur1 = cur1->prev;
		}
	}
	else {
		if (remember != 0) {
			number* temporary = new number;
			if (remember != 0) {
				temporary->data = remember;
				temporary->prev = NULL;
				cur1->prev = temporary;
				temporary->next = cur1;
				cur1 = cur1->prev;
			}
		}
	}
}
void outputform(number* pH) {
	number* cur = pH;
	if (pH == NULL) {
		cout << " Nothing to do here.";
		return;
	}
	cout << " ";
	while (cur->prev != NULL) {
		cur = cur->prev;
	}
	while (cur != NULL) {
		cout << cur->data;
		cur = cur->next;
	}
}
bool sosanh(numberlist one, numberlist two) {
	number* cur1 = one.pT;
	number* cur2 = two.pT;
	if (cur1 == NULL || cur2 == NULL || (cur1 == NULL && cur2 == NULL))
		cout << " Nothing to do here.";
	bool check = true;
	number* travel1 = one.pT;
	number* travel2 = two.pT;
	while (travel1->prev != NULL && travel2->prev != NULL) {
		travel1 = travel1->prev;
		travel2 = travel2->prev;
	}
	if (travel1->prev == NULL && travel2->prev != NULL) {
		check = false;
	}
	else if (travel1->prev == NULL && travel2->prev == NULL) {
		while (true) {
			if (travel1->data > travel2->data) {
				check = true;
				break;
			}
			else if (travel1->data < travel2->data) {
				check = false;
				break;
			}
			else {
				travel1 = travel1->next;
				travel2 = travel2->next;
			}
		}
	}
	return check;
}
void divide2(numberlist one, numberlist two) {
	int dem = 0;
	if (sosanh(one, two) == true) {
		while (sosanh(one, two) == true) {
			add2(two, two);
			dem++;
		}
	}
	else {
		while (sosanh(one, two) != true) {
			add2(one, two);
			dem++;
		}
	}
	cout << dem;
}
