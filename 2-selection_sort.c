#include "sort.h"

/**
* selection_sort - sorts using the selection sort algorithm
* @array: the array to be sorted
* @size: size of the array
*
* Return: Always Void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int is_swap, temp;

	is_swap = 0;
	for (i = 0; i < size - 1; i++)
	{
		is_swap = 0;
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				is_swap = 1;
			}
		}
		if (is_swap)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
