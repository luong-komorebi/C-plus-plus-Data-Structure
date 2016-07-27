#pragma once
class Stack
{
private:
	int *data;
	int top;
	int size;
public:
	Stack();
	void makeStack(int m);
	bool empty();
	void push(int t);
	int pop();
	void makeEmpty();
	int numberOfElements();
};
