#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int main()
{
    list* list = create_list();
    
    length_of_list(list);
    
    char item1 [] = "A";
    add_to_list(list, "A");
    
    char item2 [] = "B";
    add_to_list(list, "B");
    
    char item3 [] = "C";
    add_to_list(list, "C");
    
    print_list(list);
    
    remove_from_list(list);
    
    flush_list(list);
    
    free_list(list);
    
    return 0;
}
