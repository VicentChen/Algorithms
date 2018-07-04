#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void KMP(char* pat, int** dfa)
{
	int len = strlen(pat);
	int X = 0;
	for (int c = 0; c < 256; c++)
		dfa[c][X] = 0;
	dfa[pat[0]][0] = 1;
	for (int j = 1; j < len; j++)
	{
		for (int c = 0; c < 256; c++)
		{
			dfa[c][j] = dfa[c][X];
		}
		// dfa[pat[j]][j] = 1;
		dfa[pat[j]][j] = j + 1;
		X = dfa[pat[j]][X];

		for (int i = 0; i < 256; i++)
			printf("%d ", dfa[i][j]);
		printf("\n");
	}
}

int search(char* txt, int** dfa, char* pat)
{
	int len = strlen(txt);
	int status = 0, patlen = strlen(pat);
	int i;
	for (i = 0; i < len && status < patlen; i++)
	{
		status = dfa[txt[i]][status];
		printf("%d ", status);
	}
	if (status == patlen) return i - patlen;
	else return 0;
}

int main(int argc, char* argv[])
{
	char *txt = "BCBAABACAABABACAA";
	char *pat = "ABABAC";

	int len = strlen(pat);
	int** dfa = (int **)malloc(sizeof(int*) * 256);
	for (int i = 0; i < 256; i++)
	{
		dfa[i] = (int *)malloc(sizeof(int)*len);
	}
	int offset = 0;
	KMP(pat, dfa);
	offset = search(txt, dfa, pat);
	printf("%d\n", offset);
	printf("%s\n", txt);
	for (int i = 0; i < offset; i++)
		printf(" ");
	printf("%s\n", pat);

	for (int i = 0; i < len; i++)
	{
		free(dfa[i]);
	}
	free(dfa);
	return 0;
}
