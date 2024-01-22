#include "sort.h"
/**
 *insertion_sort_list-  sorts a doubly linked list insertion sort
 *@list: the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if ((*list)->next == NULL || list == NULL || *list == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list((const listint_t *)*list);
		}
	}
}
