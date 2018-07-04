#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int M = 0;
const int N = 14;
const int R = 256;
char** aux = (char**)malloc(sizeof(char*)*N);

void init(char** strings);

char charAt(char* string, int index)
{
	if (index < strlen(string))
		return string[index];
	else
		return -1;
}

void selectSort(char** strings, int lo, int hi, int d)
{
	char* temp;
	if (strings[lo][d] > strings[hi][d])
	{
		temp = strings[hi];
		strings[hi] = strings[lo];
		strings[lo] = temp;
	}
}

void sort(char** strings, int lo, int hi, int d)
{
	if (lo + M >= hi)
	{
		selectSort(strings, lo, hi, d);
		return;
	}

	int count[R + 2] = { 0 };
	for (int i = 0; i < N; i++)
		count[charAt(strings[i], d) + 1]++;

	for (int i = 0; i < R + 1; i++)
		count[i + 1] += count[i];

	for (int i = lo; i <= hi; i++)
		aux[count[charAt(strings[i], d)]++] = strings[i];

	for (int i = lo; i <= hi; i++)
		strings[i] = aux[i - lo];
}

void MSD(char** strings)
{
	sort(strings, 0, N - 1, 0);
}

int main(int argc, char* argv[])
{
	char** strings = (char**)malloc(sizeof(char*)*N);
	init(strings);
	MSD(strings);

	for (int i = 0; i < N; i++)
	{
		printf("%s\n", strings[i]);
	}
}

void init(char** strings)
{
	strings[0] = "she";
	strings[1] = "sells";
	strings[2] = "seaashells";
	strings[3] = "by";
	strings[4] = "the";
	strings[5] = "sea";
	strings[6] = "shore";
	strings[7] = "the";
	strings[8] = "shells";
	strings[9] = "she";
	strings[10] = "sells";
	strings[11] = "are";
	strings[12] = "surely";
	strings[13] = "seashells";
}