#include "list.h"

/* Allocate space for a new list and set its head to NULL.
 * Returns the created list if successful, NULL otherwise. */
list* create_list(){
    // allocate memory and set head to NULL
    list* ll = (list*)malloc(sizeof(list));
    ll->head = NULL;
    return ll;
}

/* Check the length of the list */
int len_of_list(list* ll){
    // initialize len to 0 and start with head node
    int num_items = 0;
    node* current = ll->head;
    
    // iterate (traverse) through linked list incrementing for every item
    while(current != NULL){
        num_items++;
        current = current->next;
    }

    return num_items;
}

/* Allocates a new node and copies the string from item to this node
 * (use malloc, strlen, and strncpy; or try strdup). Adds this new node
 * to end of the list ll. Returns 0 if successful, non−zero otherwise. */
int add_to_list(list* ll, char* item){
    int init_len = len_of_list(ll);
    
    // make next node 
    node* new_node = (node*)malloc(sizeof(node));
    new_node->item = strdup(item);
    new_node->next = NULL;

    // point to node
    // check if linked list is empty
    if (ll->head == NULL){
        ll->head = new_node;
    } 
    // otherwise the linked list is not empty
    else {
        // start at first node
        node* current = ll->head;
        // find the last node
        while(current->next != NULL){
            current = current->next;
        }
        // point to next node
        current->next = new_node;
    }

    // check if the length increased by 1
    int new_len = len_of_list(ll);
    if (new_len == init_len + 1){
        // printf("%d\n", new_len);
        return 0;
    } else {
        return 1;
    }
}

/* Removes the head of the list ll, extracts the string stored in the head,
 * and returns a pointer to this string. Also frees the removed head node. */
char* remove_from_list(list* ll){
    // start at head
    node* current = ll->head;
    
    // check if linked list is not empty
    if (current != NULL){
        // save item
        char* item = current->item;
        // move head to second element (which may be NULL)
        ll->head = current->next;
        free(current);
        return item;
    } 
    // otherwise list is empty
    else {
        return NULL;
    }
}

/*Prints every string in each node of the list ll, with a new line
 * character at the end of each string */
void print_list(list* ll){
    // start at head
    node* current = ll->head;
    // iterate through all but one item of linked list and print item
    for (int i = 0; i < len_of_list(ll) - 1; ++i){
        printf("%s, ", current->item);
        current = current->next;
    }

    // print last item with newline 
    if (current != NULL){
        printf("%s\n", current->item);
    } 
    // otherwise print newline, linked list was empty
    else {
        printf("\n");
    }
    
}

/* Flushes (clears) the entire list and re−initializes the list. The passed
 * pointer ll should still point to a valid, empty list when this function
 * returns. Any memory allocated to store nodes in the list should be freed.
 */
void flush_list(list* ll){
    // start at head
    node* current = ll->head;
    node* next;

    // iterate (traverse) through linked list
    while(current != NULL){
            // find next node before freeing current
            next = current->next;

            // free current node and move to next node
            free(current);
            current = next;
    }

    // set head to NULL
    ll->head = NULL;
}

/* De−allocates all data for the list. Ensure all memory allocated for list
 * ll is freed, including any allocated strings and list ll itself. */
void free_list(list* ll){
    // free memory for all nodes
    flush_list(ll);
    
    // free memory for linked list
    free(ll);
}