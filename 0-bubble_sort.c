#include "sort.h"

/**
 * bubble_sort - A func to sort integers in ascending order using bubble sort
 * @array: Input of an array of integers
 * @size: Input size of the array
 * Return: None
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	bool swapped;

	for (i = 0; i < size; i++)
	{
		swapped = false;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
			break;
	}
}

