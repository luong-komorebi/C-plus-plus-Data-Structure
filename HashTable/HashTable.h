#pragma once

/* Number of slots in the hash table array. */
#define NSLOTS 128

/*
* Data structure definitions.
*/

/*
* Declaration of the linked list `node' struct.
*/

typedef struct _node
{
	char *key;
	int value;
	struct _node *next; /* pointer to the next node in the list */
} node;

/*
* Declaration of the hash table struct.
* 'slot' is an array of node pointers, so it's a pointer to a pointer.
*/

typedef struct
{
	node **slot;
} hash_table;


/*
* Function declarations.
*/

/*** Hash function. ***/

int hashMe(char *s);


/*** Linked list utilities. ***/

/* Create a single node whose 'next' field is NULL. */
node *create_node(char *key, int value);

/* Free all the nodes of a linked list. */
void free_list(node *list);


/*** Hash table utilities. ***/

hash_table *create_hash_table(void);

void free_hash_table(hash_table *ht);

/*
* Look for a key in the hash table.  Return 0 if not found.
* If it is found return the associated value.
*/
int get_value(hash_table *ht, char *key);

/*
* Set the value stored at a key.  If the key is not in the table,
* create a new node and set the value to 'value'.  Note that this
* function alters the hash table that was passed to it.
*/
void set_value(hash_table *ht, char *key, int value);

/* Print out the contents of the hash table as key/value pairs. */
void print_hash_table(hash_table *ht);


