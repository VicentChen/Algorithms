#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 100

void dijkstra(int matrix[6][6], int N, int* path, int length, int step, int origin, int prev[6])
{
	int* distance = (int*)malloc(sizeof(int)*N);
	int* mark = (int*)malloc(sizeof(int)*N);
	int temp, min, currentNode = origin;

	// ��ʼ���������顢�������
	for (int k = 0; k < N; ++k)
	{
		distance[k] = INT_MAX;
		mark[k] = 1;
	}
	distance[origin] = 0; // �����������Ϊ0

	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < N; ++k) // ѡȡ��ǰ��С���
		{
			min = INT_MAX; // ��ʼ�����·��
			if ((min > distance[k]) && mark[k])
			{
				min = distance[k];
				currentNode = k;
			}
		}
		mark[currentNode] = 0; // ѡȡ����Ϊ�Ѿ���
		printf("current Node: %d    ", currentNode);
		for (int k = 0; k < N; ++k) // ����distance����
		{
			if (distance[k] > matrix[currentNode][k] + distance[currentNode]) // ��ǰ���k��origin�ľ��� > currentNode��origin�ľ��� + currenNode��k�ľ���
			{
				prev[k] = currentNode;
				distance[k] = matrix[currentNode][k] + distance[currentNode];
			}
			printf("%3d ", distance[k]);
		}
		printf("\n");
	}

	for (int i = 0; i < N; ++i)
	{
		if (origin == i)
			continue;
		printf("origin -> %d: distance = %d\n", i, distance[i]);
		printf("    %d<-", i);
		temp = i;
		while (prev[temp] != origin)
		{
			printf("%d<-", prev[temp]);
			temp = prev[temp];
		}
		printf("%d\n", origin);
	}

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", prev[i]);
	}
	printf("\n");

	free(distance);
	free(mark);
}

int main(int argc, char* argv[])
{
	int N = 6;
	int path[6];
	int length = INT_MAX;
	int step = 0, origin = 3;
	int matrix[6][6] =
	{
		{0,2,1,4,INT_MAX,1},
		{2,0,7,INT_MAX,5,INT_MAX},
		{1,7,0,3,INT_MAX,INT_MAX},
		{4,INT_MAX,3,0,2,INT_MAX},
		{INT_MAX,5,INT_MAX,2,0,3},
		{1,INT_MAX,INT_MAX,INT_MAX,3,0}
	};
	int prev[6];

	dijkstra(matrix, N, path, length, step, origin, prev);
	return 0;
}
