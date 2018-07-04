#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main(int argc, char* argv[])
{
	double result[8][6];
	for (int i = 0; i < 6; i++)
	{
		result[0][i] = PI * i / 3;
		result[1][i] = cos(result[0][i]);
	}
	for (int i = 2; i < 8; i++)
	{
		for (int j = i - 1; j < 6; j++)
		{
			result[i][j] = (result[i - 1][j] - result[i - 1][j - 1]) / (result[0][j] - result[0][j - i + 1]);
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		printf("%8.4lf", result[1][i]);
	}
	printf("\n");

	for (int i = 2; i < 8; i++)
	{
		for (int j = 0; j < i - 1; j++)
			printf("        ");
		for (int j = i - 1; j < 6; j++)
			printf("%8.4lf", result[i][j]);
		printf("\n");
	}
}
