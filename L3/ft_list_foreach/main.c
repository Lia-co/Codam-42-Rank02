#include "ft_list.h"
#include <stdio.h>

void print_val(void *val)
{
	printf("%d\n", *(int *)val);
}

int main(void)
{
	int	a = 1;
	int b = 2;
	int c = 3;
	t_list node3 = {NULL, &c};
	t_list node2 = {&node3, &b};
	t_list node1 = {&node2, &a};

	t_list *my_list = &node1;
	ft_list_foreach(my_list, print_val);
	return 0;
}