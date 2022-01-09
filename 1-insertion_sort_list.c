#include "sort.h"

/**
* insertion_sort_list - sorts a list using insertion sort method
* @list: the list to be sorted
*
* Return: Always Void
**/
void insertion_sort_list(listint_t **list)
{
	listint_t *comp_r, *temp, *current;

	if (list == NULL || *list == NULL || len_list(*list) < 2)
		return;

	for (comp_r = (*list)->next; comp_r != NULL; comp_r = temp)
	{
		temp = comp_r->next;
		current = comp_r->prev;
		while (current != NULL && comp_r->n < current->n)
		{
			current->next = comp_r->next;
			if (comp_r->next != NULL)
				comp_r->next->prev = current;
			comp_r->prev = current->prev;
			comp_r->next = current;
			if (current->prev != NULL)
				current->prev->next = comp_r;
			else
				*list = comp_r;
			current->prev = comp_r;
			current = comp_r->prev;
			print_list(*list);
		}
	}
}

/**
 * len_list - returns the number of elements in a linked dlistint_t list
 * @h: pointer to a dlistint_t list
 *
 * Return: the number of nodes
 */
size_t len_list(const listint_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
