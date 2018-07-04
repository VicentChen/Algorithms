#include <stdio.h>

int main(int argc, char* argv[])
{
	// 初始化矩阵
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

	double max; int maxIndex;
	double temp;
	for (int i = 0; i < 300; i++)
	{
		// 选列主元
		max = matrix[i][i];
		maxIndex = i;
		for (int k = i; k < 300; k++)
		{
			if (matrix[k][i] > max)
			{
				max = matrix[k][i];
				maxIndex = k;
			}
		}
		for (int k = i; k <= 300; k++)
		{
			temp = matrix[i][k];
			matrix[i][k] = matrix[maxIndex][k];
			matrix[maxIndex][k] = temp;
		}
	
		// 消元
		double cofficient;
		for (int k = i + 1; k < 300; k++)
		{
			cofficient = - matrix[k][i] / matrix[i][i];
			for (int j = i; j <= 300; j++)
			{
				matrix[k][j] += cofficient * matrix[i][j];
			}
		}
	}
	
	// 求解
	double x[300] = { 0 };
	for (int i = 299; i >= 0; i--)
	{
		for (int k = i + 1; k <300; k++)
		{
			matrix[i][300] -= x[k] * matrix[i][k];
		}
		x[i] = matrix[i][300] / matrix[i][i];
	}

	for (int i = 0; i < 300; i++)
	{
		printf("x%d=%lf\n", i, x[i]);
	}
	return 0;
}
