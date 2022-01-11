#include "sort.h"

/**
* shell_sort - sorts array using the shell sort algorithm
* @array: the array
* @size: size of the array
*
* Return: Always Void
*/
void shell_sort(int *array, size_t size)
{
	size_t i, gap;

	gap = 1;
	if (array == NULL || size < 2)
		return;

	while (gap < size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = 0; i < size; i++)
			shell_sort_main(array, size, gap, i);
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

/**
* shell_sort_main - sorts array using the shell sort algorithm
* @array: the array
* @size: size of the array
* @gap: interval that subdivide the array
* @index: initial position to sort
*
* Return: Always Void
*/
void shell_sort_main(int *array, size_t size, size_t gap, size_t index)
{
	size_t i, j, min;
	int is_swapped, temp;

	is_swapped = 0;
	for (i = index; i < size; i = i + gap)
	{
		is_swapped = 0;
		min = i;
		for (j = i + gap; j < size; j = j + gap)
		{
			if (array[j] < array[min])
			{
				min = j;
				is_swapped = 1;
			}
		}
		if (is_swapped)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}
