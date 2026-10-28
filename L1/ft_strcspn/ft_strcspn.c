#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;

    while(*s != *reject && *s)
    {
        i++;
        s++;
    }
    return i;
}

// int main(void)
// {
//     printf("%li\n", strcspn("hiiiiiiiabc", "i"));
//     printf("%li\n", ft_strcspn("hiiiiiiiabc", "i"));
// }