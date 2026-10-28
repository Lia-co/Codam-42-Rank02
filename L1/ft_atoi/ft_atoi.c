#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
    int num = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num * sign);
}

// int main(void)
// {
//     printf("ft_atoi:%i\n", ft_atoi("-a123"));
//     printf("atoi: %i\n", atoi("-a123"));
// }




