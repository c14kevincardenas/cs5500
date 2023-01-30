#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int main()
{
    list* list = create_list();
    
    char item1 [] = "A"; /*gives a character to test*/
    add_to_list(list, "A");
    
    char item2 [] = "B";
    add_to_list(list, "B");
    
    char item3 [] = "C";
    add_to_list(list, "C");
    
    /*remove_from_list(list);*/
    
    print_list(list);
    
    /*flush_list(list);*/
    
    /*free_list(list);*/
    
    return 0;
}
