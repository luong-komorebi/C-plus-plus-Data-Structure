#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include <iostream>
using namespace std;


/*** Hash function. ***/

int hashMe(char *s)
{
	int a = 0;
	for (int i = 0; i < strlen(s); i++) {
		a += s[i];
	}
	return a%NSLOTS;
}


/*** Linked list utilities. ***/

/* Create a single node. */
node *create_node(char *key, int value)
{
	node* create = new node;
	create->key = key;
	create->value = value;
	create->next = NULL;
	return create;
}


/* Free all the nodes of a linked list. */
void free_list(node *list)
{
	if (list == NULL) {
		return;
	}
	node* cur = list->next;
	while (cur != NULL) {
		node* temp = cur;
		cur = cur->next;
		delete temp;
	}
}


/*** Hash table utilities. ***/

/* Create a new hash table. */
hash_table *create_hash_table()
{
	hash_table* Table;
	Table = new hash_table;
	Table->slot = new node*[NSLOTS];
	for (int i = 0; i < NSLOTS; i++) {
		Table->slot[i] = new node;
		Table->slot[i]->key = NULL;
		Table->slot[i]->value = 0;
		Table->slot[i]->next =NULL;
	}
	return Table;
}


/* Free a hash table. */
void free_hash_table(hash_table *ht)
{
	for (int i = 0; i < NSLOTS; i++) {
		free_list(ht->slot[i]);
	}
	delete[] ht->slot;
}


/*
* Look for a key in the hash table.  Return 0 if not found.
* If it is found return the associated value.
*/
int get_value(hash_table *ht, char *key)
{
	int getHash = hashMe(key);
	node* cur = ht->slot[getHash];
	cur = cur->next;
	while (cur != NULL) {
		if (strcmp(cur->key,key)==0)
			return cur->value;
		else cur = cur->next;
	}
	return -1;

}


/*
* Set the value stored at a key.  If the key is not in the table,
* create a new node and set the value to 'value'.  Note that this
* function alters the hash table that was passed to it.
*/
void set_value(hash_table *ht, char *key, int value)
{
	int getHash = hashMe(key);
	node* cur = ht->slot[getHash];
	while (cur->next!=NULL) {
		if (strcmp(cur->next->key,key)==0) {
			cur->next->value = value;
			return;
		}
		else cur = cur->next;
	}
	
	node* temp = create_node(key, value);
	cur->next = temp;

}


/* Print out the contents of the hash table as key/value pairs. */
void print_hash_table(hash_table *ht)
{
	cout << " \n\n Hastable : \n";
	for (int i = 0; i < NSLOTS; i++) {
		ht->slot[i] = ht->slot[i]->next;
		while (ht->slot[i] != NULL) {
			cout << ht->slot[i]->key << "  " << ht->slot[i]->value;
			cout << endl;
			ht->slot[i] = ht->slot[i]->next;
		}
	}
}

