#pragma once
struct Book {
	char title[201];
	char isbn[11];
	char author[41];
	char lang[31];
	int year;
	float dollars;
	int stock;
	Book* next;

};
void initialize(Book* &pH);
void addABook(Book* &pH);
void sellABook(Book* pH, char ISBN[]);
void findSub(char Name[], Book* pH);
void removeBook(Book* &a);
void remK(Book* &pH, int k);

