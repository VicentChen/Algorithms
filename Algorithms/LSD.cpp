#include <stdio.h>

struct KeyValuePair
{
	char key;
	char* value;
};

const int N = 13;
const int R = 7;

void init(struct KeyValuePair* key_value_pair);

void KeyIndexedCount(struct KeyValuePair* key_value_pair, struct KeyValuePair* aux)
{
	int count[256] = { 0 };
	for (int i = 0; i < N; i++)
	{
		count[key_value_pair[i].key]++;
	}
	for (int i = 1; i < 256; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = 0; i < N; i++)
	{
		aux[count[key_value_pair[i].key - 1]++] = key_value_pair[i];
	}
	for (int i = 0; i < N; i++)
	{
		key_value_pair[i] = aux[i];
	}
}

int main(int argc, char* argv[])
{
	struct KeyValuePair key_value_pair[N];
	struct KeyValuePair aux[N];
	init(key_value_pair);

	for (int i = R - 1; i >= 0; i--)
	{
		for (int k = 0; k < N; k++)
		{
			key_value_pair[k].key = (key_value_pair[k].value)[i];
		}
		KeyIndexedCount(key_value_pair, aux);
		for (int j = 0; j < N; j++)
		{
			printf("%s\n", key_value_pair[j].value);
		}
		printf("\n");
	}


}

void init(struct KeyValuePair* key_value_pair)
{
	key_value_pair[0].value = "4PGC938";
	key_value_pair[1].value = "2IYE230";
	key_value_pair[2].value = "3CIO720";
	key_value_pair[3].value = "1ICK750";
	key_value_pair[4].value = "1OHV845";
	key_value_pair[5].value = "4JZY524";
	key_value_pair[6].value = "1ICK750";
	key_value_pair[7].value = "3CIO720";
	key_value_pair[8].value = "10HV845";
	key_value_pair[9].value = "10HV845";
	key_value_pair[10].value = "2RLA629";
	key_value_pair[11].value = "2RLA629";
	key_value_pair[12].value = "3ATW723";
}