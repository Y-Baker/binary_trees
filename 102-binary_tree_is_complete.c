#include "binary_trees.h"

void free_queue(queue_t *head);

/**
 * new_node - Function that creates a new_node in a Queue
 * @node: pointer of node to be created
 * Return: the node created
 */
queue_t *new_node(binary_tree_t *node)
{
	queue_t *new;

	new =  malloc(sizeof(queue_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->node = node;
	new->next = NULL;

	return (new);
}


/**
 * queue_push - push new node
 * @node: node of the tree
 * @head: head node of queue
 * @tail: tail node of queue
 */
void queue_push(binary_tree_t *node, queue_t *head, queue_t **tail)
{
	queue_t *new;

	new = new_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}


/**
 * free_queue - free the queue
 * @head: node of queue
 */
void free_queue(queue_t *head)
{
	queue_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}


/**
 * queue_pop - Function that pops a node into the stack
 * @head: Type head node of in the stack
 */
void queue_pop(queue_t **head)
{
	queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}


/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: node of the tree
 * Return: 1 if is complete 0 if it is not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *head, *tail;
	int state = 0;

	if (tree == NULL)
		return (0);

	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (state == 1)
			{
				free_queue(head);
				return (0);
			}
			queue_push(head->node->left, head, &tail);
		}
		else
			state = 1;
		if (head->node->right != NULL)
		{
			if (state == 1)
			{
				free_queue(head);
				return (0);
			}
			queue_push(head->node->right, head, &tail);
		}
		else
			state = 1;
		queue_pop(&head);
	}
	return (1);
}
