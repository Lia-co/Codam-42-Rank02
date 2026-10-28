// skip leading spaces/tabs → start index of first word
// find end of first word (space/tab/'\0')
// save [start, end) as first_word (malloc end-start+1, copy, null-terminate)

// i = end
// loop:
//     skip spaces/tabs at i
//     if argv[1][i] == '\0': break
//     write a single ' ' if this isn't the very first word printed
//     write characters until next space/tab/'\0'

// if first_word is non-empty and we printed at least one other word:
//     write ' '
// write first_word
// write '\n'
// free(first_word)

#include <unistd.h>
#include <stdlib.h>

void rostring(int argc, char **argv);

int main(int argc, char **argv)
{
	rostring(argc, argv);
	return 0;
}

void rostring(int argc, char **argv)
{
	int word_str;
	int word_end;
	int word_len;
	int i;
	int j;
	int print_any;
	char *first_word;
	
	if (argc < 2)
	{
		write(1, "\n", 1);
		return ;
	}
	word_str = 0;
	while (argv[1][word_str] == ' ' || (argv[1][word_str] == '\t'))
		word_str++;
	word_end = word_str;
	while (argv[1][word_end] != '\0' && argv[1][word_end] != ' ' && argv[1][word_end] != '	')
		word_end++;
	word_len = word_end - word_str;
	first_word = malloc(word_len + 1);
	if (first_word == NULL)
		return ;
	i = 0;
	while (i < word_len)
	{
		first_word[i] = argv[1][word_str];
		i++;
		word_str++;
	}
	first_word[i] = '\0';

	j = word_end;
	print_any = 0;
	while (1)
	{
		while (argv[1][j] == ' ' || argv[1][j] == '	')
			j++;
		if (argv[1][j] == '\0')
			break ;
		if (print_any)
			write(1, " ", 1);
		while (argv[1][j] != ' ' && argv[1][j] != '	' && argv[1][j] != '\0')
		{
			write(1, &argv[1][j], 1);
			j++;
		}
		print_any = 1;
	}
	if (print_any == 1)
		write(1, " ", 1);
	i = 0;
	while (first_word[i] != '\0')
	{
		write(1, &first_word[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(first_word);
}