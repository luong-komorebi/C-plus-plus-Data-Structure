#pragma once
#include<iostream>
#include<locale>
#include<io.h>
#include<fcntl.h>
#include<codecvt>
#include <cstdlib>
#include<fstream>
#include<tchar.h>
#include<Windows.h>
using namespace std;
struct node
{
	wstring word;
	wstring content;
	node * left, *right;
};
void insertword(node * &root, wstring word, wstring content);
void insertcontent(node * &root, wstring word, wstring content);
void inputfromfile(node *& root, node * &root1);
node * findbyword(node * root, wstring word);
void findbycontent(node * root, wstring content);
void deltree(node *& root);
void printtree(node * root);
node * removeusingright(node * root, wstring key);
node * removeusingleft(node * root, wstring key);
node * findmin(node * root);
node * findmax(node* root);
void outputpreorder(node * root);
void editcontent(node * root, wstring word);