#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char *string = "acaabaaabc";
	char *subString = "aab";

	int index = 0, subIndex = 0;
	int length = strlen(string);
	int subLength = strlen(subString);

	for (int i = 0; i < length - subLength; i++)
	{
		index = i; subIndex = 0;
		while (string[index] == subString[subIndex])
		{
			index++;
			subIndex++;
		}
		if (subIndex == subLength)
			printf("%d-%d\n", i+1, index);
	}
}
