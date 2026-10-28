/*Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>*/

#include <unistd.h>

int main(int argc, char **argv)
{
	char *s;
	int i = 0;

	if (argc == 2)
	{
		s = argv[1];
		while (s[i] != '\0')
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = 155 - s[i];
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = 219 - s[i];
			write(1, &s[i], 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return 0;
}