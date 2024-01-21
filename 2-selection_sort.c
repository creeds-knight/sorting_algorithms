#include "sort.h"

/**
 * selection_sort - A function that uses selection of min numbers for sorting
 * @array: Input array to be sorted
 * @size: Size of the array to be sorted
 * Return: None
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < (size - 1); i++)
	{
		min_idx = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
			swap(&array[min_idx], &array[i]);
		print_array(array, size);
	}
}
