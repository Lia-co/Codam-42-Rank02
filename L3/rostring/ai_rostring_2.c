// no malloc/free at all. Just remember where does the word start
// next_word is useful to print ' ', find the fw and write the rest.
// is_sep centralize the check

#include <unistd.h>

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t');
}

/* advance *i past a word starting at *i, return its start/end via pointers */
static int	next_word(char *s, int *i, int *start, int *end)
{
	while (is_sep(s[*i]))
		(*i)++;
	if (s[*i] == '\0')
		return (0);
	*start = *i;
	while (s[*i] != '\0' && !is_sep(s[*i]))
		(*i)++;
	*end = *i;
	return (1);
}

void	rostring(int argc, char **argv)
{
	char	*s;
	int		i;
	int		fw_start;
	int		fw_end;
	int		start;
	int		end;
	int		printed;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return ;
	}
	s = argv[1];
	i = 0;
	if (!next_word(s, &i, &fw_start, &fw_end))
	{
		write(1, "\n", 1);
		return ;
	}
	printed = 0;
	while (next_word(s, &i, &start, &end))
	{
		if (printed)
			write(1, " ", 1);
		write(1, &s[start], end - start);
		printed = 1;
	}
	if (printed)
		write(1, " ", 1);
	write(1, &s[fw_start], fw_end - fw_start);
	write(1, "\n", 1);
}