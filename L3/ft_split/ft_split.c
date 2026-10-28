/*EXAM QUESTION
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc, free

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

/* Pseudocode
check if a character is a delimiter;
calculate num of substrings;
get the length of each substring;
malloc enough memory for the array (num_substring), and ends in NULL pointer;
return an array of string;
free the array;
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

static int	is_dmt(char c);
static int	wd_num(char *str);
static int  wd_len(char *str, int start);
static char *wd_dup(char *str, int wd_str, int len);
char    **ft_split(char *str);

int main(void)
{
	char *str = "three words apart (null)";
    char **arr = ft_split(str);
    int i = 0;
    
    while(arr[i] != NULL)
    {
        printf("%s\n", arr[i]);
        i++;
    }
    free(arr);
    return 0;
}

char    **ft_split(char *str)
{
	char **arr;
	int i;
    int j;

	i = 0;
    j = 0;
    arr = malloc(sizeof(char *) * (wd_num(str) + 1));
    if (!arr || !str)
        return (NULL);
	else 
    {
        while (str[i] != '\0')
        {
            // if not white spaces
            if(!is_dmt(str[i]))
            {
                // copy word into arr
                arr[j] = wd_dup(str, i, wd_len(str, i));
                j++;
                i += wd_len(str, i);
            }
            // skip white spaces
            else
                i++;
        }
        arr[j] = NULL;
	    return arr;
	}
}

static int	is_dmt(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int wd_num(char *str)
{
    int i;
    int wd_num;

    i = 0;
    wd_num = 0;
    while(str[i] != '\0')
    {
        //when starting without delimiter, increment
        if (i == 0 && !is_dmt(str[i]))
            wd_num++;
        // find the delimiter
        else if ((!is_dmt(str[i]) && is_dmt(str[i-1])))
            wd_num++;
        i++;
    }
    return wd_num;
}

static int  wd_len(char *str, int start)
{
    int wd_str;
    // loop into the string
    if(str[start] == '\0')
        return 0;
    // skip ' ' \t \n
    while(is_dmt(str[start]))
        start++;
    // find the start of the word
    wd_str = start;
    // keep going into the word and stops at delimiter
    while(!is_dmt(str[start]) && str[start] != '\0')
            start++;
    // len = cursor - wd_str
    return (start - wd_str);
}

static char *wd_dup(char *str, int wd_str, int len)
{
    char *wd_dup;
    int i;

    i = 0;
    wd_dup = malloc(sizeof(char) * (len + 1));
    if (!wd_dup)
        return NULL;
    while(i < len)
    {
        wd_dup[i] = str[wd_str + i];
        i++;
    }
    wd_dup[i] = '\0';
    return wd_dup;
}