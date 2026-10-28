#ifndef SORT_LIST_H
#define SORT_LIST_H

#include <stddef.h>

int ascending(int a, int b);
typedef struct s_list t_list;

struct s_list {
    int data;
    t_list *next;
};

int ascending(int a, int b)
{
	return (a <= b);
}

#endif