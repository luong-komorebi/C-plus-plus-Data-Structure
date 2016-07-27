#pragma once
class Queue {
private : 
	int* data;
	int in;
	int out;	
	int size;
public :
	Queue();
	void makeQueue(int m);
	bool checkEmpty();
	void enqueue(int t);
	void dequeue();
	void makeEmpty();
	int numberOfElements();
};
