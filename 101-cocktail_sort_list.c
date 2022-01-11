#include "sort.h"

/**
* cocktail_sort_list - sorts a list using the cocktail algorithm
* @list: pointer to the list
*
* Return: Always Void
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int is_swapped;

	is_swapped = 1;
	if (!list || len_list(*list) < 2)
		return;

	current = *list;
	while (is_swapped)
	{
		for (is_swapped = 0; current->next;)
		{
			if (current->next->n < current->n)
			{
				swap_node(list, current);
				print_list(*list);
				is_swapped++;
			}
			else
				current = current->next;
		}
		if (!is_swapped)
			break;
		for (is_swapped = 0; current->prev;)
		{
			if (current->prev->n > current->n)
			{
				swap_node(list, current->prev);
				print_list(*list);
				is_swapped++;
			}
			else
				current = current->prev;
		}
	}
}

/**
* swap_node - swaps two nodes in the list
* @list: pointer to the list
* @node: node to be swapped
*
* Return: Always Void
*/
void swap_node(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
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
