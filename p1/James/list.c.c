#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

/*allocate space for new list and set its head to null; Returns created list - otherwise Null*/
list* create_list(){
    list* ll = (list*) malloc(sizeof(list));
    node *head = (node*)malloc(sizeof(node));
    ll->head = NULL;
    printf("created new list at %p\n", ll); /*check that function creates list*/
    return ll;
};

/*Allocate new node and copies string item to this node; add this new node to end of list 11*/
int add_to_list(list* ll, char* item){
    node* current = ll->head; /*identifies head node*/
    node* new_node = (node*)malloc(sizeof(node));  /*make the node*/
    new_node->item = strdup(item); /*reference the node to the item*/
    new_node->next = NULL; /*puts node at end of list*/
    
    if (ll->head == NULL){ /*if this is first node created*/
        ll->head = new_node;
    } else{ /*put the node in last of list*/
        while(current->next != NULL){
            current = current->next;
            current->next = new_node;
        }
    }

    printf("item value is: %s\n", new_node->item); /*simple check if item is copied*/
    printf("item is located at: %p\n", new_node->item); /*simple check for item address*/
}

/*Remove head from list 11; extract the string stored in head; return a pointer to this string*/
char* remove_from_list(list* ll){
    node* current = ll->head; /*identifies head node*/
    if (ll->head == NULL){
        printf("List is at the end");
    }
    else {
        node* temp = ll->head; /*create temp for new head*/
        temp->item;
        printf("item value is %s\n", temp->item); /*check that item is returned*/
        ll->head = current->next; /*move head to next node*/
        free (temp);
        printf("item value is %p\n", current->next->item); /*check to make sure it's not there*/
        return current->next->item;
    }
}

/*prints nodes in the list*/
void print_list(list* ll){
    node* current = ll->head; /*identifies current head*/
    node* next = current->next; /*points to next node*/
    while (current->next != NULL);{
        printf("Node value is %s\n", current->item);
        current = current->next;
    }
}

/*flushes and reinitializes list*/
void flush_list(list* ll){
    node* current = ll->head; /*sets our current node*/
    node* next = current->next; /*node pointer points to next node*/
    
    while (current != NULL){
        free(current);
        current = next;
    }
    ll->head == NULL; /*reinialize empty set*/
    printf("List is at %p\n", ll->head); /*checks if new list is initialized*/
    printf("No nodes at %p\n", current); /*checks if memory has been freed*/
}

/*completely destroys list and frees the memory*/
void free_list(list* ll){
    node* current = ll->head; /*sets our current node*/
    node* next = current->next; /*node pointer points to next node*/
    
    while (current != NULL){
        free(current);
        current = next;
    }
    /*check that all memory is freed - should retun null*/
    printf("Node is available at %p\n", current);
}



