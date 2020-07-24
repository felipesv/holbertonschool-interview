#include "lists.h"
/**
 * insert_node - insert node on sorted linked list
 * @head: head of the list
 * @number: number of the new node
 *
 * Return: address of new node or null
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
	listint_t *current = NULL;

	if (head == NULL)
		return (NULL);

	current = *head;
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;

	if (current == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (current->next)
	{
		if (current->next->n > number)
		{
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}
		current = current->next;
	}

	current->next = new_node;
	return (new_node);
}
