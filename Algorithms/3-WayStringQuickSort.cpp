#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 14;

void init(char** strings);

void exch(char** strings, int a, int b)
{
	char* temp;
	temp = strings[a];
	strings[a] = strings[b];
	strings[b] = temp;
}

char charAt(char* string, int index)
{
	if (index < strlen(string))
		return string[index];
	else
		return -1;
}

void sort(char** strings, int lo, int hi, int d)
{
	if (lo >= hi)
		return;
	char standard = charAt(strings[lo], d);
	int lt = lo, ht = hi;
	int i = lt + 1;
	while (i <= ht)
	{
		if (strings[i][d] > standard)
			exch(strings, i, ht--);
		else if (strings[i][d] < standard)
			exch(strings, i++, lt++);
		else
			i++;
	}
	sort(strings, lo, lt - 1, d);
	if (standard >= 0) sort(strings, lt, ht, d + 1);
	sort(strings, ht + 1, hi, d);
}

void quickSort(char** strings)
{
	sort(strings, 0, N - 1, 0);
}

int main(int argc, char* argv[])
{
	char** strings = (char**)malloc(sizeof(char*)*N);
	init(strings);
	quickSort(strings);
	
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