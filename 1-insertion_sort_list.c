#include "sort.h"

/**
 * insertion_sort_list - A function to sort a list using insertion
 * @list: Input list to be sorted
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur;
	listint_t *idx;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;
	while (cur != NULL)
	{
		idx = cur->prev;
		while (idx != NULL && idx->n > cur->n)
		{
			tmp = cur->next;
			if (tmp != NULL)
				tmp->prev = idx;
			idx->next = tmp;
			if (idx->prev != NULL)
				idx->prev->next = cur;
			else
				*list = cur;
			cur->prev = idx->prev;
			cur->next = idx;
			idx->prev = cur;

			idx = cur->prev;
			print_list(*list);
		}
		cur = cur->next;
	}
}
