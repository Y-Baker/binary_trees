#include "binary_trees.h"
#include "10-binary_tree_depth.c"

void insert_to_queue(queue_t **queue, const binary_tree_t *node);
void binary_tree_traverse(const binary_tree_t *tree, queue_t **queue);
void free_queue(queue_t *head);

/**
 * binary_tree_levelorder - go through tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t **head, *tmp;

	if (!tree || !func)
		return;
	head = malloc(sizeof(queue_t *));
	*head = NULL;
	binary_tree_traverse(tree, head);
	tmp = *head;
	while (tmp)
	{
		func(tmp->node->n);
		tmp = tmp->next;
	}
	free_queue(*head);
	free(head);
}


/**
 * insert_to_queue - insert to queue
 * @queue: the queue to add to it
 * @node: the node to be added
*/
void insert_to_queue(queue_t **queue, const binary_tree_t *node)
{
	size_t depth;
	queue_t *new_queue_node;
	queue_t *head, *tmp;

	if (node || queue)
	{
		depth = binary_tree_depth(node);
		new_queue_node = malloc(sizeof(queue_t));
		new_queue_node->node = (binary_tree_t *)node;
		new_queue_node->depth = depth;
		if (!*queue)
		{
			new_queue_node->next = NULL;
			*queue = new_queue_node;
			return;
		}
		head = *queue;
		while (head)
		{
			if (!head->next || head->next->depth > depth)
			{
				tmp = head->next;
				head->next = new_queue_node;
				new_queue_node->next = tmp;
				return;
			}
			head = head->next;
		}
	}
}


/**
 * binary_tree_traverse - go throw tree and add to queue
 * @queue: the queue to add to it
 * @tree: the tree to traverse
*/
void binary_tree_traverse(const binary_tree_t *tree, queue_t **queue)
{
	if (!tree)
		return;

	insert_to_queue(queue, tree);

	if (tree->left)
		binary_tree_traverse(tree->left, queue);

	if (tree->right)
		binary_tree_traverse(tree->right, queue);
}


/**
 * free_queue - free the queue
 * @head: the head of the queue
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
