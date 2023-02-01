#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

/*allocate space for new list and set its head to null; Returns created list - otherwise Null*/
list* create_list(){
    list* ll = (list*) malloc(sizeof(list));
    ll->head = NULL;
    printf("created new list at %p\n", ll); /*check that function creates list*/
    return ll;
}

/*count the list of nodes*/
int length_of_list(list* ll){
    int num_items = 0;
    node* current = ll->head;
    
    /*iterate (traverse) through linked list incrementing for every item*/
    while(current != NULL){
        num_items++;
        current = current->next;
    }
    return num_items;
}

/*Allocate new node and copies string item to this node; add this new node to end of list 11*/
    int add_to_list(list* ll, char* item){
    
    int init_length = length_of_list(ll);
    
    node* new_node = (node*)malloc(sizeof(node));  /*make the node*/
    new_node->item = strdup(item); /*reference the node to the item*/
    new_node->next = NULL; /*puts node at end of list*/
    
    if (ll->head == NULL){ /*if this is first node created*/
        ll->head = new_node;
    } else
    { /*put the node in last of list*/
        node* current = ll->head; /*identifies head node*/
        while(current->next != NULL){
            current = current->next; /*keeps iterating the list until last node*/
        }
        current->next = new_node;
    }

    printf("item value is: %s\n", new_node->item); /*simple check if item is copied*/
    printf("item is located at: %p\n", new_node->item); /*simple check for item address*/
    
     /* check if the length increased by 1*/
    int new_length = length_of_list(ll);
    if (new_length == init_length + 1){
        printf("%d\n", new_length);
        return 0;
    } else {
        return 1;
    }
}

/*Remove head from list 11; extract the string stored in head; return a pointer to this string*/
char* remove_from_list(list* ll){
    node* current = ll->head; /*identifies head node*/
    if (ll->head == NULL){
        printf("List is empty");
    }
    else {
        ll->head = current->next; /*move head to next node*/
        current->next->item;
        printf("item value is %s\n", current->next->item); /*check that item is returned*/
        free (current);
        return current->next->item;
    }
}

/*prints nodes in the list*/
void print_list(list* ll){
    node* current = ll->head; /*identifies current head*/
        
    /*iterate through all but one item of linked list and print item*/
    for (int i = 0; i < length_of_list(ll); ++i){
        printf("%s\n", current->item);
        current = current->next;
        }
    }

/*flushes and reinitializes list*/
void flush_list(list* ll){
    node* current = ll->head; /*sets our current node*/
    node* next = current->next; /*node pointer points to next node*/
    
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    
    ll->head == NULL; /*reinialize empty set*/
}

/*completely destroys list and frees the memory*/
void free_list(list* ll){
    node* current = ll->head; /*sets our current node*/

    flush_list(ll);

    free(ll);

    /*check that all memory is freed - should retun null*/
    printf("Node is available at %p\n", current);
}



