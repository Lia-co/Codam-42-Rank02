/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	char *s;

	if (argc == 2)
	{
		s = argv[1];
		while(s[i] != '\0')
		{
			if(s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = s[i] + ('a' - 'A');
				s[i - 1] = '_';
				write(1, &s[i - 1], 1);
			}
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return 0;
}