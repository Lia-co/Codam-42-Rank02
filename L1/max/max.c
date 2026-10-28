#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    unsigned int max_i = 0;
    unsigned int i = 0;

    if (len <= 0)
        return 0;
    while(i <= len - 1)
    {
        if (tab[i] < tab[i + 1])
            max_i = i + 1;
        i++;
    }
    return tab[max_i - 1];
}

// int main(void)
// {
//     int tab[] = {1, 2, 3, 4};
//     printf("%i\n", max(tab, 4));
// }