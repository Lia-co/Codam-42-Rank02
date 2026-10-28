#include <stdlib.h>
#include <stdio.h>

void fprime(int argc, char **argv)
{
	int d = 2; 
	if (argc = 2)
	{
		int num = atoi(argv[1]);
		if (num <= 0)
		{
			printf("\n");
			return ;
		}
		if (num == 1)
		{
			printf("%i\n", num);
			return ;
		}
		while(num > 0 && d * d <= num)
		{
			while (num % d == 0)
			{
				printf("%i", d);
				num = num / d;
				if(num != 1)
					printf("*");
				else
					printf("\n");
			}
			d++;
		}
		if (num > 1)
		printf("%i\n", num);
	}
	printf("\n");
	return ;
}

int main(int argc, char **argv)
{
	fprime(argc, argv);
	return 0;
}