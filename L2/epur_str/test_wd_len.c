#include <unistd.h>
#include <stdio.h>

static int wd_len(char *str)
{
    int i = 0;

    // && instead of ||, since all three condtions need to be satisfied
    while((str[i]) != ' ' && str[i] != '\t' && str[i] != '\0')
        i++;
    return i;
}

int main(void)
{
    char *str = "Hi";

    printf("%d", wd_len(str));
}