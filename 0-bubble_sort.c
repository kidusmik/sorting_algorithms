#include "sort.h"

/**
* bubble_sort - sorts an array of integers using bubble sort
* @array: The array
* @size: size of the array
*
* Return: Always Void
*/
void bubble_sort(int *array, size_t size)
{
	size_t total, i;
	int tmp;

	i = 0;
	if (size <= 2)
		return;
	while (1)
	{
		total = 0;
		i = 0;
		while (i < size)
		{
			if (i == size - 1)
				break;
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
			else
				total++;
			i++;
		}
	if (total == size - 1)
		break;
	}
}
