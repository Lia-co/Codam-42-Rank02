/*Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c :

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include <stddef.h>
// #include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int ft_list_size(t_list *tab)
{
	int i = 0;
	t_list *tmp;

	tmp = tab;
	while(tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return i;
}

// int main(void)
// {
// 	int a = 1;
// 	int b = 2;
// 	int c = 3;

// 	t_list node3 = {NULL, &c};
// 	t_list node2 = {&node3, &b};
// 	t_list node1 = {NULL, &a};
// 	printf("%d", ft_list_size(NULL));
// }