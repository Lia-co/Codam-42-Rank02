/*Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/

#include <unistd.h>
#include <stdio.h>

static void epur_str(char *str);
static int wd_len(char *str);
static int skip_spc(char *str, int i);

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        epur_str(argv[1]);
    }
    else
        write(1, "\n", 1);
}

static void epur_str(char *str)
{
    int i = 0;
    int first_wd = 1;

    i = skip_spc(str, i);
    while(str[i] != '\0')
    {
        if(first_wd == 0)
            write(1, " ", 1);
        write(1, str + i, wd_len(str + i));
        i = i + wd_len(str + i);
        first_wd = 0;
        i = skip_spc(str, i);
    }
    write(1, "\n", 1);
}

// static int is_del(char c)
// {
//     return(c == ' ' || c == '\t' || c == '\0');
// }

static int wd_len(char *str)
{
    int i = 0;

    while((str[i]) != ' ' && str[i] != '\t' && str[i] != '\0')
        i++;
    return i;
}

static int skip_spc(char *str, int i)
{
    if(str[i] == ' ' || str[i] == '\t')
        i++;
    return i;
}