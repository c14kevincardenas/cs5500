#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(){
    // TEST CREATE_LIST //
    printf("1. CREATE_LIST TEST\n");
    list* ll = create_list();
    // verify length of ll is 0
    int len = len_of_list(ll);
    printf("Length of newly created list: %d\n", len);

    // TEST ADD_TO_LIST //
    printf("\n2. TEST ADD_TO_LIST\n");
    // test add one element to empty list
    int check = add_to_list(ll, "Kevin");
    printf("0 if first add was successful: %d\n", check);
    printf("Length after add one element: %d\n", len_of_list(ll));
    // test add second element to list of 1
    check = add_to_list(ll, "James");
    printf("0 if second add was successful: %d\n", check);
    printf("Length after add second element: %d\n", len_of_list(ll));

    // TEST PRINT_LIST
    printf("\n3. TEST PRINT_LIST\n");
    // test print with items
    printf("Here is the list: ");
    print_list(ll);

    // TEST REMOVE_FROM_LIST
    printf("\n4. TEST REMOVE_FROM_LIST\n");
    // remove head and verify len = 1
    char* item = remove_from_list(ll);
    printf("Length after remove head: %d\n", len_of_list(ll));
    printf("Removed item: %s\n", item);
    printf("Here is the remaining list: ");
    print_list(ll);

    // TEST FLUSH_LIST
    printf("\n5. TEST FLUSH_LIST\n");
    // add three items to test flush
    add_to_list(ll, "Kevin");
    add_to_list(ll, "James");
    add_to_list(ll, "Noah");
    // before flush
    printf("Before flush length: %d\n", len_of_list(ll));
    printf("Here is the list: ");
    print_list(ll);
    // test flush
    flush_list(ll);
    printf("After flush length: %d\n", len_of_list(ll));
    // test printing with 0 items
    printf("Here is the list: ");
    print_list(ll);
    // test remove with 0 items
    item = remove_from_list(ll);
    printf("Removed item: %s\n", item);

    // TEST FREE_LIST
    printf("\n6. TEST FREE_LIST\n");
    free_list(ll);
    printf("Printing the freed list should cause a Segmentation fault\n");
    print_list(ll);

    return 0;
}