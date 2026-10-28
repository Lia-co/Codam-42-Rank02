/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end);
static void	swap(int *start, int *end);
static int arr_len(int start, int end);

int main(void)
{
	int *arr;
	int start = 0;
	int end = -3;
	int len;
	int i = 0;
	
	len = arr_len(start, end);
	arr = ft_rrange(start, end);
	while (len > 0)
	{
		printf("%d\n", arr[i]);
		i++;
		len--;
	}
	free(arr);
	return 0;
}

static void	swap(int *start, int *end)
{
		int tmp = 0;
		tmp = *start;
		*start = *end;
		*end = tmp;
		(void)tmp;
}

static int arr_len(int start, int end)
{
	int len = 0;

	if (start > end)
		swap(&start, &end);
	if (start >= 0 || end >= 0)
		len = end - start + 1;
	else if (start < 0 && end < 0)
		len = (-start) + end + 1;
	return len;
}

int     *ft_rrange(int start, int end)
{
	int len = 0;
	int *arr;
	int i;

	if (start > end)
		swap(&start, &end);
	// printf("start: %d\n", start);
	// printf("end: %d\n", end);
	len = arr_len(start, end);
	arr = malloc(sizeof(int) * len);
	i = 0;
	while (len > 0)
	{
		arr[i] = start;
		start++;
		i++;
		len--;
	}
	return arr;
}