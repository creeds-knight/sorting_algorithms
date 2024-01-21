#include "sort.h"

/**
 * swap - A function to swap the values of two numbers
 * @pos_1: The first position
 * @pos_2: The second position
 * Return: None
 */

void swap(int *pos_1, int *pos_2)
{
	int tmp = *pos_1;
	*pos_1 = *pos_2;
	*pos_2 = tmp;
}
