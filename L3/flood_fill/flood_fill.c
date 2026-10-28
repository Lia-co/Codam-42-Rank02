#include <stdio.h>

typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

static void fill(char **tab, t_point size, t_point start, char target)
{
	//bounds check
	if (start.x < 0 || start.x >= size.x || start.y < 0 || start.y >= size.y)
		return ;
	//character check
	if (tab[start.y][start.x] != target)
		return ;
	//fill start pos as 'F' first and then 4-direction cells
	tab[start.y][start.x] = 'F';
	fill(tab, size, (t_point){start.x - 1, start.y}, target);
	fill(tab, size, (t_point){start.x + 1, start.y}, target);
	fill(tab, size, (t_point){start.x, start.y - 1}, target);
	fill(tab, size, (t_point){start.x, start.y + 1}, target);
}


void  flood_fill(char **tab, t_point size, t_point begin)
{
	//tab check
    if(!tab || size.x <= 0 || size.y <= 0)
		return ;
    //fill up the area from the start
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

#include <stdlib.h>
#include <stdio.h>


char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}