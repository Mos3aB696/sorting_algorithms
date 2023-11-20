#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers in ascending order using
 * the Insertion sort algorithm
 * @list: pointer to the list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		
		while (temp && temp->prev && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			if (temp->prev->prev)
				temp->prev->prev->next = temp;
			else
				*list = temp;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			print_list(*list);
		}
		current = current->next;
	}
}
