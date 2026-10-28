/* EXAM QUESTION
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

/*Pseudocode
helper function1: to_lower;
	if c >= 'A' || c <= 'F'
		c = c + ('a' - 'A');
helper function2: get_digit, which takes char c and base_num, and return an int;
	find the max_digit in base range and convert max_digit into char
	if base_num <= 10
		max_digit = base_num + '0'
	if base_num > 10 && <= 16
		max_digit = (base_num - 10) + 'a'

	convert char c into digit, c need to be compared with max_digit
	if(c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	if(c >= 'a' && c <= 'e" && c <= max_digit)
		return (c + 10 - 'a');
	else
		return (-1);
	
atoi_base function:
negative sign;
num = 0;
while loop go through each letter from left to right until the '\0', where get_digit = -1	
	num = num * base;
	num = num + (digit * sign)
	str++;

*/

#include <stdio.h>

char to_lower(char c)
{
	if(c >= 'A' && c <= 'F')
		return (c + ('a' - 'A'));
	else
		return c;
}

int get_digit(char c, int str_base)
{
	char max_digit;

	if (str_base <= 10)
		max_digit = str_base + '0';
	else if (str_base > 10 && str_base <= 16)
		max_digit = (str_base - 10) + 'a';
	
	if(c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if(c >= 'a' && c <= 'f' && c <= max_digit)
		return (c + 10 - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int n;
	int sign = 1;
	int digit;

	n = 0;
	if(*str == '-')
	{
		sign = -1;
		str++;
	}
	while((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		n = n * str_base;
		n = n + (digit * sign);
		str++;
	}
	return n;
}

int main(void)
{
	char *str = "FF";
	int n = ft_atoi_base(str, 16);
	printf("int: %d\n", n);

	// printf("digit: %x\n", get_digit('b', 16));
	return 0;
}