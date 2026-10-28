#include <unistd.h>

// void fizzbuzz()
// {
// 	int		i;
// 	char	n;

// 	i = 1;
// }

char *itoa(int i)
{
	int		len;
	char 	chr;
	
	while (i < 10)
	{
		chr = i + '0';
		write(1, &chr, 1);
		write(1, "\n", 1);
	}
	while (i <= 100)
	{
		chr = (i % 10) + '0';
		write(1, &chr, 1);
		chr = (i / 10) + '0';
		write(1, &chr, 1);
	}
}

int main()
{
	itoa(100);
}