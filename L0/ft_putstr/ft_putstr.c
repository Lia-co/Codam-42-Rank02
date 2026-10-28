#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
// why this version is wrong? and how to run gdb?
void	ft_putstr(char *str)
{
	while (str)
	{
		write(1, str, 1);
		str++;
	}
}

int main()
{
	ft_putstr("Hello");
	return (0);
}