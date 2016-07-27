#include "function.h"
#include <iostream>
using namespace std;

Queue::Queue(void) {
	data = NULL;
}
void Queue::makeQueue(int m){
	size = m;
	out = 0;
	in = -1;
	data = new int[size];
}
bool Queue::checkEmpty() {
	return (in < out? true : false);
}
void Queue::enqueue(int t) {
	if (in == size - 1)
		cout << " Queue is full!";
	else {
		data[++in] = t;
	}
}
void Queue::dequeue() {
	if (checkEmpty())
		cout << " Nothing to dequeue!\n";
	else {
		cout << data[out] << endl;
		out++;
	}
}
void Queue::makeEmpty() {
	if (checkEmpty()) {
		cout << " Nothing to empty!\n";
	}
	else {
		delete[] data;
		size = 0;
	}
}
int Queue::numberOfElements() {
	return (in-out+1);
}