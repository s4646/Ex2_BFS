#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "my_mat.h"

#define ROWS 10
#define COLS 10

void printMat(int mat[][10])
{

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", mat[i][j]); // equals to *(mat + i*10 + j)
		}
		printf("\n");
	}
}

int main()
{

	int mat[ROWS][COLS];

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			mat[i][j] = 0;
		}
	}

	char c;
	do
	{
		scanf(" %c", &c);
		if (c == 'A')
		{
			A(mat);
		}
		if (c == 'B')
		{
			int i, j;
			scanf(" %d %d", &i, &j);
			if (B(mat, i, j))
			{
				printf("True");
			}
			else
			{
				printf("False");
			}
			printf("\n");
		}
		if (c == 'C')
		{
			C(mat);
		}
		if (c == 'D')
		{
			break;
		}
	} while (c != EOF);

	return 0;
}
