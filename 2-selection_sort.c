#include "sort.h"

/**
 * swap - A function to swap the numbers at different indexes
 * @pos_1: A number at the  first position
 * @pos_2:  A number at the last position
 * Return - None
 */
void swap(int *pos_1, int *pos_2)
{
	int tmp = *pos_1;
	*pos_1 = *pos_2;
	*pos_2 = tmp;
}
/**
 * selection_sort - A function that uses selection of min numbers for sorting
 * @array: Input array to be sorted
 * @size: Size of the array to be sorted
 * Return: None
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL || size < 2)
		return;
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
