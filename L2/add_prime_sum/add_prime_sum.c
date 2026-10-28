/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$
*/

/*
two while loop
while (num > 0)
{
	while(d >= 2 && d < num)
		d++;
	num--;
}
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int is_prime(int n);
static int ft_atoi(char *str);
static void put_nbr(int num);
static int add_prime_sum(int num);

int main(int argc, char **argv)
{
	int num = 0;
	int res = 0;

	if ((argc == 2) && (num = ft_atoi(argv[1])))
	{
		put_nbr(add_prime_sum(num));
		write(1, "\n", 1);
	}
	else
	{
		write(1, "0\n", 2);
		return 0;
	}
	return 0;
}

static int ft_atoi(char *str)
{
	int num = 0;

	while(*str != '\0')
	{
		num = num * 10;
		num = num + (*str - '0');	
		str++;
	}
	return num;
}

static int is_prime(int n)
{
	int d = 2;
	while(d < n)
	{
		if (n % d == 0)
			return (0);
		d++;
	}
	return (1);
}

static int add_prime_sum(int num)
{
	int res = 0;

	while(num > 1)
	{
		if(is_prime(num))
		{
			// printf("prime: %d\n", num);
			res = res + num;
		}
		num--;
	}
	return res;
}

static void put_nbr(int num)
{
	char c = 0;
	if(num / 10 > 0)
		put_nbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}