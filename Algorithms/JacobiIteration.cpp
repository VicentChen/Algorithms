#include <stdio.h>
#include <math.h>

double max(double* num, int N)
{
	double max = num[0];
	for (int i = 1; i < N; i++)
		if (max < num[i])
			max = num[i];
	return max;
}

void Jacobi(double A[3][3], double* b, double* x, double e)
{
	double temp;
	for (int i = 0; i < 3; i++)
	{
		temp = A[i][i];
		for (int j = 0; j < 3; j++)
			A[i][j] /= -temp;
		A[i][i] = 0;
		b[i] /= temp;
	}

	double t[3], y[3];
	double deviation;
	do
	{
		for (int i = 0; i < 3; i++)
		{
			y[i] = 0;
			for (int j = 0; j < 3; j++)
			{
				y[i] += A[i][j] * x[j];
			}
			y[i] += b[i];
			t[i] = fabs(x[i] - y[i]);
		}
		deviation = max(t, 3);
		for (int i = 0; i < 3; i++)
		{
			x[i] = y[i];
			printf("x%d=%lf\t", i, x[i]);
		}
		getchar();
	}
	while (deviation >= e);
}

int main(int argc, char* argv[])
{
	double A[3][3] = { {10, -1, -2}, {-1, 10, -2}, {-1, -1, 5} };
	double b[3] = { 7.2, 8.3, 4.2 };
	double x[3] = { 1.02, 1.13, 1.24 };
	double e = 0.001;

	Jacobi(A, b, x, e);

	return 0;
}
