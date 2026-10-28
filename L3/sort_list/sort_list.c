/* EXAM QUESTION
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------
Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.
Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
LIST.H FILE:

typedef struct s_list t_list;

struct s_list {
    int data;
    t_list *next;
};
YOU MUST TEST WITH YOUR LIST.H FILE JUST FOR THIS SHELL.
*/

/*Pseudocode
declare a pointer to a temp list
while loop goes through all elements in temp pointer
    if not ascending
        swap
        go back to start position
    else
        position moving
return sorted list
*/

#include "list.h"
#include <stdio.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *tmp = lst;
    int swap_data = 0;

    // printf("tmp: %p\n", tmp);
    while (lst->next != NULL)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            swap_data = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap_data;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return lst;
}

int main(void)
{
    t_list node3 = {1, NULL};
    t_list node2 = {2, &node3};
    t_list node1 = {3, &node2};
    
    t_list *lst = &node1;
    t_list *sorted_lst;

    while (lst != NULL)
    {
        // printf("lst: %p\n", lst);
        printf("data: %i\n", lst->data);
        lst = lst->next;
    }

    sorted_lst = sort_list(&node1, cmp);
    while (sorted_lst != NULL)
    {
        // printf("sorted_lst: %p\n", sorted_lst);
        printf("data: %i\n", sorted_lst->data);
        sorted_lst = sorted_lst->next;
    }
    return 0;
}
