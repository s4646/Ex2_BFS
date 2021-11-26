#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define ROWS 10
#define COLS 10

// hi from my_mat
int A(int mat[][10])
{
	// int a;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			scanf(" %d", &mat[i][j]); // equals to *(mat + i*10 + j)
		}
	}
	return 0;
}

int B(int mat[10][10], int i, int j)
{
	int visit[10] = {-1};
	int index = 0, pointer = 1;
	visit[index] = i;
	bool route = true;

	while (route && index < 10)
	{
		int tmp = visit[index];
		for (int k = 0; k < 10; k++)
		{
			if (mat[tmp][k])
			{
				bool kVisited = false;
				for (int m = 0; m < pointer; m++)
				{
					if (visit[m] == k)
					{
						kVisited = true;
					}
				}
				if (!kVisited)
				{
					visit[pointer] = k;
					pointer++;
				}
			}
		}
		if (visit[index] == -1)
		{
			route = false;
		}
		for (int m = 0; m < 10 && visit[0] != j; m++)
		{
			if (visit[m] == j)
				return 1;
		}
		index++;
	}
	return 0;
}

void C(int mat[][10])
{
	int a, b;
	scanf(" %d %d", &a, &b);

	if (!B(mat, a, b))
	{
		printf("-1\n");
		return;
	}

	int dist[ROWS][COLS];

	// init distances
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			if (i == j)
			{
				dist[i][j] = 0;
			}
			else if (mat[i][j] != 0)
			{
				dist[i][j] = mat[i][j];
			}
			else
			{
				dist[i][j] = INT_MAX;
			}
		}
	}
	// main algorithm
	int i, j, k;
	for (k = 0; k < 10; ++k)
	{
		for (i = 0; i < 10; ++i)
		{
			for (j = 0; j < 10; ++j)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j] && (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX))
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	printf("%d\n", dist[a][b]);
}