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
