#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

static void print_bits(unsigned char octet)
{
	int i = 8;
	char bit;

	while(i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int main(void)
{
	unsigned char octet = 36;
	print_bits(octet);
	write(1, "\n", 1);
	print_bits(swap_bits(octet));
	write(1, "\n", 1);
}