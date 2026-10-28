#include <unistd.h>

static void put_nbr(int n);

int main(int argc, char **argv)
{
	// if (argc == 1)
	// {
	// 	write(1, "0", 1);
	// 	write(1, "\n", 1);
	// 	return 0;
	// }
	put_nbr(10000);
	write(1, "\n", 1);
	return 0;
}

static void put_nbr(int n)
{
	char c;
	while(n > 9)
		put_nbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}