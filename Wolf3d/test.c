#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int 	size = 3;
	int 	sizet = 4;
	int		**to;
	int		i;
	int		j;
	int 	a = 3;
	int 	b = 4;
	int 	ac = 0;
	int 	bc = 0;
	int 	count = 0;
	int		num[a][b];
	int		**map;

	while (ac < a)
	{
		bc = 0;
		while (bc < b)
		{
			num[bc][ac] = count;
			printf("%d \n", num[a][b]);
			count++;
			ac++;
		}
		bc++;
		ac = 0;
	}
	bc = 0;
	to = (int **)malloc(sizeof(int*) * size + 1);
	while (i < size)
	{
		to[i] = (int *)malloc(sizeof(int) * size);
		j = 0;
		while (j < sizet)
		{
			printf("%d \n", num[i][j]);
			to[i][j] = num[i][j];
			j++;
		}
		to[i][j] = -1;
		i++;
	}
	to[i] = NULL;
	return (0);
}