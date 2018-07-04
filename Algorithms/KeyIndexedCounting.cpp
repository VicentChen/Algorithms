#include <stdio.h>

struct KeyValuePair
{
	int key;
	char* value;
};

void init(struct KeyValuePair* key_value_pair);

int main(int argc, char* argv[])
{
	const int N = 20;
	const int R = 5;
	struct KeyValuePair key_value_pair[N];
	init(key_value_pair);

	int count[R] = { 0 };
	struct KeyValuePair aux[N];

	for (int i = 0; i < N; i++)
	{
		count[key_value_pair[i].key]++;
	}
	for (int i = 1; i < R; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = 0; i < N; i++)
	{
		aux[count[key_value_pair[i].key - 1]++] = key_value_pair[i];
	}
	for (int i = 0; i < N; i++)
	{
		printf("%02d     %s\n", aux[i].key, aux[i].value);
	}
	return 0;
}

void init(struct KeyValuePair* key_value_pair)
{
	key_value_pair[0] = { 2, "Anderson" };
	key_value_pair[1] = { 3, "Brown" };
	key_value_pair[2] = { 3, "Davis" };
	key_value_pair[3] = { 4, "Garcia" };
	key_value_pair[4] = { 1, "Harris" };
	key_value_pair[5] = { 3, "Jackson" };
	key_value_pair[6] = { 4, "Johnson" };
	key_value_pair[7] = { 3, "Jones" };
	key_value_pair[8] = { 1, "Martin" };
	key_value_pair[9] = { 2, "Martinez" };
	key_value_pair[10] = { 2, "Miller" };
	key_value_pair[11] = { 1, "Moore" };
	key_value_pair[12] = { 2, "Robinson" };
	key_value_pair[13] = { 4, "Smith" };
	key_value_pair[14] = { 3, "Taylor" };
	key_value_pair[15] = { 4, "Thomas" };
	key_value_pair[16] = { 4, "Thompson" };
	key_value_pair[17] = { 2, "White" };
	key_value_pair[18] = { 3, "Willims" };
	key_value_pair[19] = { 4, "Willson" };
}
