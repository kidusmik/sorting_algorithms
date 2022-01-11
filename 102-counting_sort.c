#include "sort.h"

/**
* counting_sort - sorts an array using counting algorithm
* @array: the array
* @size: size of the array
*
* Return: Always Void
*/
void counting_sort(int *array, size_t size)
{
	int i, j, k, temp, *final;

	if (!array || size < 2)
		return;
	k = 0;
	for (i = 0; i < (int)size; i++)
		if (array[i] > k)
			k = array[i];

	final = malloc(sizeof(int) * ++k);
	if (!final)
		return;
	for (i = 0; i < k; i++)
		final[i] = 0;
	for (i = 0; i < (int)size; i++)
		final[array[i]] += 1;

	for (i = j = 0; i < k && j < (int)size; i++)
	{
		temp = final[i];
		while (temp > 0)
		{
			array[j] = i;
			temp--;
			j++;
		}
	}

	temp = 0;
	for (i = 0; i < k; i++)
	{
		temp += final[i];
		final[i] = temp;
	}

	print_array(final, k);
	free(final);
}
