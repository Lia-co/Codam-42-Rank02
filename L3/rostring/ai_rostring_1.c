#include <unistd.h>
#include <stdlib.h>

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t');
}

static void	write_word(char *s, int start, int end)
{
	write(1, &s[start], end - start);
}

void	rostring(int argc, char **argv)
{
	char	*s;
	int		i;
	int		word_start;
	int		word_end;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return ;
	}
	s = argv[1];

	/* find first word's [word_start, word_end) */
	i = 0;
	while (is_sep(s[i]))
		i++;
	word_start = i;
	while (s[i] != '\0' && !is_sep(s[i]))
		i++;
	word_end = i;

	/* print every remaining word, separated by single spaces */
	while (1)
	{
		while (is_sep(s[i]))
			i++;
		if (s[i] == '\0')
			break ;
		write_word(s, i, i + 0); // placeholder, see below
	}
}

