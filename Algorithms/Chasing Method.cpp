#include <stdio.h>

int main(int argc, char* argv[])
{
	double matrix[300][301] = { 0 };
	matrix[0][0] = 2; matrix[0][1] = 1; matrix[0][300] = 3;
	matrix[299][299] = 2; matrix[299][298] = 1; matrix[299][300] = 3;
	for (int i = 1; i < 299; i++)
	{
		matrix[i][i - 1] = 1;
		matrix[i][i] = 2;
		matrix[i][i + 1] = 1;
		matrix[i][300] = 4;
	}

	double cofficient;
	for (int i = 1; i < 299; i++)
	{
		cofficient = -matrix[i][i - 1] / matrix[i - 1][i - 1];
		matrix[i][i - 1] += cofficient * matrix[i - 1][i - 1];
		matrix[i][i] += cofficient * matrix[i - 1][i];
		matrix[i][i + 1] += cofficient * matrix[i - 1][i + 1];
		matrix[i][300] += cofficient*matrix[i - 1][300];
	}
	cofficient = -matrix[299][298] / matrix[298][298];
	matrix[299][299] += cofficient * matrix[298][299];
	matrix[299][300] += cofficient * matrix[298][300];

	double x[300] = { 0 };
	x[299] = matrix[299][300] / matrix[299][299];
	for (int i = 298; i >= 0; i--)
	{
		x[i] = (matrix[i][300] - matrix[i][i + 1] * x[i + 1]) / matrix[i][i];
	}

	for (int i = 0; i < 300; i++)
	{
		printf("x%d=%lf\n", i + 1, x[i]);
	}
	return 0;
}
