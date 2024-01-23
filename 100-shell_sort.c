#include "sort.h"
/**
 * shell_sort - A function to sort an array using knuth sequence
 * @array: Input Array to be sorted
 * @size: Size of the input array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t gap;
	int tmp;

	gap = 1;
	while (gap <= (size / 3))
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
