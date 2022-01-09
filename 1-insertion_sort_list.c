#include "sort.h"

/**
* insertion_sort_list - sorts a list using insertion sort method
* @list: the list to be sorted
*
* Return: Always Void
**/
void insertion_sort_list(listint_t **list)
{
	listint_t *comp_r, *comp_l, *tmp, *temp2, *temp3, *current;

	current = *(list);
	while (1)
	{
		comp_l = current->prev;
		comp_r = current->next;
		while (comp_l != NULL)
		{
			if (current->n < comp_l->n)
				comp_l = comp_l->prev;
			else
			{
				tmp = comp_l->next;
				comp_l->next = current;
				tmp->prev = current;
				temp2 = current->prev;
				temp3 = current->next;
				current->prev = comp_l;
				current->next = tmp;
				temp2->next = temp3;
				temp3->prev = temp2;
				print_list(*(list));
				break;
			}
		}
		current = comp_r;
		if (comp_r == NULL)
			break;
	}
}
