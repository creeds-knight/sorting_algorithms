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
 * lomuto_partition - A function to return the index of the pivot
 * @array: Input array
 * @size: size of array
 * @low: Lower Index
 * @high: Higher index
 * Return: Index i
 */
size_t lomuto_partition(int *array, size_t size, size_t low, size_t high)
{
	size_t i, j;
	int pivot = array[high];

	i = low - 1;

	for (j = low; j <= (high - 1); j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	i++;
	swap(&array[i], &array[high]);
	print_array(array, size);
	return (i);
}

/**
 * lomuto_sort - A function to sort the array recusively
 * @array: Input array
 * @size: Size of array
 * @low: Lower index
 * @high: Higer index
 * Return: None
 */

void lomuto_sort(int *array, size_t size, size_t low, size_t high)
{
	size_t pivot;

	if (low >= high)
		return;
	pivot = lomuto_partition(array, size, low, high);
	if (pivot > low)
		lomuto_sort(array, size, low, pivot - 1);
	if (pivot < high)
		lomuto_sort(array, size, pivot + 1, high);
}

/**
 * quick_sort - A function to sort using quick sort algorithm
 * @array: Input Array
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !*array)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
