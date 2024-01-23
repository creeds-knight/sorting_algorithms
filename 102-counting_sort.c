#include "sort.h"

/**
 * counting_sort - A function to sort using counting sort algorithm
 * @array: Input array
 * @size: Size of the input array
 * Return: None
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	size_t max;
	int *count;
	int *new_arr;

	max = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] > array[max])
			max = i;
	}
	count = malloc((array[max] + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= (size_t)array[max]; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= (size_t)array[max]; i++)
		count[i] += count[i - 1];
	print_array(count, array[max] + 1);
	new_arr = malloc(size * sizeof(int));
	if (new_arr == NULL)
	{
		free(count);
		return;
	}
	for (i = size - 1; i < size; i--)
		new_arr[--count[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = new_arr[i];
	free(new_arr);
	free(count);
}
