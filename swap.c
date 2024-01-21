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
