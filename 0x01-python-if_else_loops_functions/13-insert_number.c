#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - a func that inserts a number in a list
 * @head: data type double pointer of list
 * @number: number to be added
 * Return: 0 if no cycle || 1 if cycle is present
 */

listint_t *insert_node(listint_t **head, int number)
{
  listint_t *node = *head;
  listint_t *new;

  new = malloc(sizeof(listint_t));

  if (new == NULL)
    return (NULL);

  new->n = number;

  if (node == NULL || node->n >= number)
    {
      new->next = node;
      *head = new;
      return (new);
    }
  while (node && node->next && node->next->n < number)

    node = node->next;
  new->next = node->next;
  node->next = new;

  return (new);
}
