#include <stdio.h>
#include "ft_list.h"

void print_int(void *data)
{
    printf("%d\n", *(int *)data);
}

int main(void)
{
    int a = 1, b = 2, c = 3;
    t_list node3 = {NULL, &c};
    t_list node2 = {&node3, &b};
    t_list node1 = {&node2, &a};

    ft_list_foreach(&node1, print_int);
    return (0);
}