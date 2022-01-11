#include "sort.h"

/**
* quick_sort - sorts array using the quick sort algorithm
* @array: the array
* @size: size of the array
*
* Return: Always Void
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_main(array, 0, size - 1, size);
}

/**
* quick_sort_main - sorts array using the quick sort algorithm
* @array: the array
* @init: start of the array
* @final: end of the array
* @size: size of the array
*
* Return: Always Void
*/
void quick_sort_main(int *array, int init, int final, size_t size)
{
	int initial, fim, i, f, pivot, aux;

	initial = init;
	i = initial;
	fim = final;
	f = fim;
	pivot = array[(i + f) / 2];
	do {
		while (array[i] < pivot)
			i++;
		while (array[f] > pivot)
			f--;
		if (i <= f)
		{
			aux = array[i];
			array[i++] = array[f];
			array[f--] = aux;
			print_array(array, size);
		}
	} while (i < f);
	if (initial < f)
		quick_sort_main(array, initial, f, size);
	if (i < fim)
		quick_sort_main(array, i, fim, size);
}
