#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
 * @list: the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	while (current != NULL)
	{
		/*we save the current node in a temporary variable*/
		tmp = current;

		/*This is the inner loop to swap the nodes*/
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;

			if (tmp->next != NULL)
			{
				tmp->next->prev = tmp->prev;
			}

			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;

			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			/*If the previous node is NULL, update the list head*/
			if (tmp->prev == NULL)
			{
				*list = tmp;
			}
			tmp->next->prev = tmp;
			/* Print the list after every swap*/
			print_list(*list);
		}
		/* We now move to the next node in the list*/
		current = current->next;
	}
}
