#include "sort.h"
void merger(int *array, int *buff, size_t lower, size_t mid, size_t higher);
void recursive_sorter(int *array, int *buff, size_t lower, size_t higher);
void merge_sort(int *array, size_t size);
/**
 * merger - A function to merge two subarrays
 * @array: Input array
 * @buff: An array to store sub arrays
 * @lower: Lower boud of array
 * @higher: Higher bound of array
 * @mid: Mid point of array
 */
void merger(int *array, int *buff, size_t lower, size_t mid, size_t higher)
{
	size_t i = lower;
	size_t j = mid + 1;
	size_t k = lower;


	printf("Merging...\n[left]: ");
	print_array(array + lower, mid - lower + 1);

	printf("Merging...\n[right]: ");
	print_array(array + mid + 1, higher - mid);
	while (i <= mid && j <= higher)
	{
		if (array[i] <= array[j])
		{
			buff[k] = array[i];
			i++;
		}
		else
		{
			buff[k] = array[j];
			j++;
		}
		k++;
	}
	while (j <= higher)
	{
		buff[k] = array[j];
		j++;
		k++;
	}
	while (i <= mid)
	{
		buff[k] = array[i];
		i++;
		k++;
	}
	for (k = lower; k <= higher; k++)
		array[k] = buff[k];
	printf("[Done]: ");
	print_array(array + lower, higher - lower + 1);
}

/**
 * recursive_sorter - A function to recursively divide and sort the array
 * @array: Input array
 * @lower: The lower bound
 * @higher: The higher bound
 * @buff: Buffer to hold sub arrays
 */

void recursive_sorter(int *array, int *buff, size_t lower, size_t higher)
{
	size_t mid;

	if (lower < higher)
	{
		mid = (lower + higher) / 2;
		recursive_sorter(array, buff, lower, mid);
		recursive_sorter(array, buff, mid + 1, higher);
		merger(array, buff, lower, mid, higher);
	}
}


/**
 * merge_sort - A function to implement the merge sort algorithm
 * @array: Input array
 * @size: Input size of array
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	recursive_sorter(array, buff, 0, size - 1);
	free(buff);
}
