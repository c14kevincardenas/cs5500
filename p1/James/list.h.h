#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*declares node*/
typedef struct Node node;

/*node in the list*/
struct Node {
    char *item; /*references item*/
    node *next; /*references next node*/
};

/*structure of the list*/
typedef struct List {
    node *head; /*references the first of the list structure*/
}list;

/*declares list name*/
list* create_list();

/*declare list to add nodes*/
int add_to_list(list* ll, char* item);

/*declare function to remove nodes from list*/
char* remove_from_list(list* ll);

/*declare function to print out nodes in a list*/
void print_list(list* ll);

/*function to flush and reinitialize list*/
void flush_list(list* ll);

/*function to deallocate all memory used for lists and delete all nodes*/
void free_list(list* ll);















