// Vo tran thanh luong
//1551020
//week 01
#include <iostream>
#include "HashTable.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	// Init the hash table
	hash_table* hashTable;
	hashTable = create_hash_table();
	// Read word from file
	ifstream file;
	file.open("input.txt");
	while (!file.eof()) {
		char* key;
		key = new char[50];
		file >> key;
		int value = get_value(hashTable, key);
		if (value == -1)
			value = 1;
		else value++;	
		set_value(hashTable, key, value);
	}
	file.close();
	// Print output to screen
	print_hash_table(hashTable);
	// Destroy the hash table (and its linked lists)
	free_hash_table(hashTable);
	system("pause");
	return 0;
}