#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Bresenham(int currentX, int currentY, int targetX, int targetY, int maxStep, int* pathX, int* pathY)
{
	int nextX = currentX;
	int nextY = currentY;
	int deltaX = targetX - currentX;
	int deltaY = targetY - currentY;
	int stepX, stepY;
	int currentStep = 0, fraction;

	deltaX < 0 ? stepX = -1 : stepX = 1;
	deltaY < 0 ? stepY = -1 : stepY = 1;
	deltaX = abs(deltaX * 2);
	deltaY = abs(deltaY * 2);
	pathX[currentStep] = nextX;
	pathY[currentStep] = nextY;
	currentStep++;

	if (deltaY > deltaX)
	{
		fraction = deltaX * 2 - deltaY;
		while (nextY != targetY)
		{
			if (fraction >= 0)
			{
				nextX += stepX;
				fraction -= deltaY;
			}
			nextY += stepY;
			fraction += deltaX;
			pathX[currentStep] = nextX;
			pathY[currentStep] = nextY;
			currentStep++;
		}
	}
	else
	{
		fraction = deltaY * 2 - deltaX;
		while (nextX != targetX)
		{
			if (fraction >= 0)
			{
				nextY += stepY;
				fraction -= deltaX;
			}
			nextX += stepX;
			fraction += deltaY;
			pathX[currentStep] = nextX;
			pathY[currentStep] = nextY;
			currentStep++;
		}
	}
	return currentStep;
}

int main(int argc, char* argv[])
{
	const int SIGHT = 10;
	int maxStep = SIGHT * SIGHT;
	int map[SIGHT][SIGHT] = {0};
	int* pathX = (int*)malloc(sizeof(int) * maxStep);
	int* pathY = (int*)malloc(sizeof(int) * maxStep);
	int step = Bresenham(0, 9, 9, 2, maxStep, pathX, pathY);
	for (int i = 0; i < step; i++)
	{
		map[pathX[i]][pathY[i]] = 1;
	}

	for (int i = 0; i < SIGHT; i++)
	{
		for (int j = 0; j < SIGHT; j++)
			printf("%d", map[i][j]);
		printf("\n");
	}
}
