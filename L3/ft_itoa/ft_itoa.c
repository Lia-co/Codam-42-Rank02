/* Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

/*Pseudocode
calculate the length of the string
recursion to strip the number into a digit until the last position
	if nbr < 0;
	if nbr == 0;
	if nbr > 0;
return a string
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


static int str_len(int nbr);

char	*ft_itoa(int nbr)
{
	char *str;
	int len;
	long num;

	num = nbr;
	len = str_len(num);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (!str)
		return NULL;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while(num > 0)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

static int str_len(int nbr)
{
	int len;
	long num;

	len = 0;
	num = nbr;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int main(void)
{
	int len;

	len = str_len(-1);
	printf("len: %d\n", len);
	printf("str: %s\n", ft_itoa(-1));
	free(ft_itoa(-1));
	return 0;
}
