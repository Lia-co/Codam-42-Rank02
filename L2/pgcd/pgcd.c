/*Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	unsigned int n1;
	unsigned int n2;
	unsigned int n;
	
	if (argc == 3 && atoi(argv[1]) != 0 && atoi(argv[2]) != 0)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[2]);
		if (n1 > n2)
			n = n1;
		else
			n = n2;
		while(1)
		{
			if (n1 % n == 0 && n2 % n == 0)
				break;
			n--;
		}
		printf("%d\n", n);
	}
	else if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
		printf("0\n");
	else
		printf("\n");
	return 0;
}