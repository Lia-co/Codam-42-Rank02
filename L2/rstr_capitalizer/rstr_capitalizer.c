/*Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts 
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

#include <unistd.h>

static void rstr_capitalizer(char *str);
static int is_spc(char c);
static int find_end(char *str);

int main(int argc, char **argv)
{
	int i = 1;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return 0;
	}	
	while (i < argc) 
	{
		rstr_capitalizer(argv[i]);
		i++;
	}
	return 0;
}

static void rstr_capitalizer(char *str)
{
	while (*str != '\0')
	{
		if (find_end(str) && *str >= 'a' && *str <= 'z')
		{
			*str = *str - ('a' - 'A');
			// write(1, str, 1);
		}
		else if (!find_end(str) && *str >= 'A' && *str <= 'Z')
		{
			*str = *str + ('a' - 'A');
			// write(1, str, 1);
		}
		write(1, str, 1);
		str++;
	}
	if (*str == '\0')
		write(1, "\n", 1);
}

static int find_end(char *str)
{
	return (!is_spc(*str) && is_spc(*(str + 1)));
}

static int is_spc(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\0');
}

