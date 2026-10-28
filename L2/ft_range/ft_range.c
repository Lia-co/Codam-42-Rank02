/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>
// #include <stdio.h>

int     *ft_range(int start, int end)
{
	int len_arr = 0;
	int *arr;
	int i = 0;

	if (start >= 0 || end >= 0)
		len_arr = end - start + 1;
	else if (start < 0 && end < 0)
		len_arr = (-start) + end + 1;
	arr = malloc(sizeof(int) * len_arr);
	while (len_arr > 0)
	{
		arr[i] = start + i;
		i++;
		len_arr--;
	}
	return arr;
}

// int main(void)
// {
// 	int start = 0;
// 	int end = 0;
// 	int len_arr = 0;
// 	if (start >= 0 || end >= 0)
// 		len_arr = end - start + 1;
// 	else if (start < 0 && end < 0)
// 		len_arr = (-start) + end + 1;
// 	int *arr = ft_range(start, end);
// 	int i = 0;

// 	while (i < len_arr)
// 	{
// 		printf("%d\n", arr[i]);
// 		i++;
// 	}
// free(arr);
// }