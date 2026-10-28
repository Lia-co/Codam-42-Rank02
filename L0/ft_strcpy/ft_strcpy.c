#include <unistd.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2 || s1 == s2)
		return (s1);
	else
	{
		while (s2[i] != '\0')
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i + 1] = '\0';
	}
	return (s1);
}

int main()
{
	char s1[6];
	char *s2 = "Hello";

	ft_strcpy(s1, s2);
	printf("%s", s1);
}