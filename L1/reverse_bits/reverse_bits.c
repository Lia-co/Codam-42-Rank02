/*Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100*/

 #include <stdio.h>

 // what is unsigned char octet?
 unsigned char	reverse_bits(unsigned char octet)
 {
	int i = 0;
	int res = 0;

	while(i < 8)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
        i++;
	}
	return res;
 }

 static void print_bit(unsigned char octet)
 {
	int i = 8;
	char bit;
	while(i--)
	{
		bit = (octet >> i & 1) + '0';
		printf("%c", bit);
	}
 }

 int main(void)
 {
	unsigned char octet = 200;
	print_bit(octet);
	printf("\n");
	print_bit(reverse_bits(octet));
	printf("\n");
	return 0;
 }