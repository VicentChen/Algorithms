#include <stdio.h>

const int SIGHT = 22;

void initializeMap(int map[SIGHT][SIGHT])
{
	for (int i = 0; i < SIGHT; i++)
		for (int j = 0; j < SIGHT; j++)
			map[i][j] = -1;
	map[2][5] = 0;
	map[2][6] = 0;
	map[2][7] = 0;
	map[3][7] = 0;
	map[4][7] = 0;
	map[5][7] = 0;
	map[5][6] = 0;
	map[5][5] = 0;
}

void BFS(int map[SIGHT][SIGHT], int currentX, int currentY, int targetX, int targetY)
{
	int queueX[SIGHT * SIGHT] = { 0 };
	int queueY[SIGHT * SIGHT] = { 0 };
	int queueLength = 0;
	int current = 0;
	queueX[current] = currentX;
	queueY[current] = currentY;
	map[currentX][currentY] = 0;

	while (current <= queueLength)
	{
		if (queueX[current] == targetX && queueY[current] == targetY)
			break;
		// вСаз╬с
		if (queueX[current] - 1 >= 0 && map[queueX[current]-1][queueY[current]] == -1)
		{
			queueLength++;
			queueX[queueLength] = queueX[current] - 1;
			queueY[queueLength] = queueY[current];
			map[queueX[current]-1][queueY[current]] = map[queueX[current]][queueY[current]] + 1;
		}
		// сраз╬с
		if (queueX[current] + 1 < SIGHT && map[queueX[current]+1][queueY[current]] == -1)
		{
			queueLength++;
			queueX[queueLength] = queueX[current] + 1;
			queueY[queueLength] = queueY[current];
			map[queueX[current]+1][queueY[current]] = map[queueX[current]][queueY[current]] + 1;
		}
		// иоаз╬с
		if (queueY[current] - 1 >= 0 && map[queueX[current]][queueY[current]-1] == -1)
		{
			queueLength++;
			queueX[queueLength] = queueX[current];
			queueY[queueLength] = queueY[current] - 1;
			map[queueX[current]][queueY[current]-1] = map[queueX[current]][queueY[current]] + 1;
		}
		// обаз╬с
		if (queueY[current] + 1 < SIGHT && map[queueX[current]][queueY[current]+1] == -1)
		{
			queueLength++;
			queueX[queueLength] = queueX[current];
			queueY[queueLength] = queueY[current] + 1;
			map[queueX[current]][queueY[current]+1] = map[queueX[current]][queueY[current]] + 1;
		}
		current++;
	}
}

int main(int argc, char* argv[])
{
	int map[SIGHT][SIGHT];
	initializeMap(map);
	BFS(map, 4, 5, 4, 8);
	for (int i = 0; i < SIGHT; i++)
	{
		for (int j = 0; j < SIGHT; j++)
			printf("%3d", map[i][j]);
		printf("\n\n");
	}
	printf("%d\n", map[2][6]);
}
