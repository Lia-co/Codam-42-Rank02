/*EXAM QUESTION
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.(?)

Input is always coherent. (?)
*/

/*Pseudocode
bubble sort method
a temp variable to storage value
loop through all numbers
	start with the first number in the array, go through each one.
		if there is mistake pair, swap values until the end of the array

*/

#include <unistd.h>
#include <stdio.h>

// void sort_int_tab(int *tab, unsigned int size)
// {
// 	int temp;
// 	int i;

// 	i = 0;
// 	while (i < (size - 1))
// 	{
// 		if (tab[i] > tab[i + 1])
// 		{
// 			temp = tab[i];
// 			tab[i] = tab[i + 1];
// 			tab[i + 1] = temp;
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
// }

// int main(void)
// {
// 	int tab[] = {1, 2, 3, 4, 5};
// 	int i;

// 	// i = 0;
// 	// while(i < 8)
// 	// {
// 	// 	printf("%i\n", tab[i]);
// 	// 	i++;
// 	// }

// 	sort_int_tab(tab, 5);
// 	i = 0;
// 	while(i < 5)
// 	{
// 		printf("%i\n", tab[i]);
// 		i++;
// 	}
// 	return 0;
// }

void sort_int_tab(int *tab, unsigned int size)
{
	int temp;
	int i;
	int j;

	j = 0;
	while (j < (size - 1))
	{
		i = j + 1;
		while(i < size)
		{
			if (tab[i] < tab[i - 1])
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
			}
			else
				i++;
		}
		j++;
	}
}

int main(){
	int tab[5] = {3, 2, 1};
	sort_int_tab(tab, 3);
	for (int i = 0; i < 3; i++)
		printf("%d ", tab[i]);
	return 0;
}