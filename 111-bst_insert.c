#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *head;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		new_node = binary_tree_node(*tree, value);
		if (!new_node)
			return (NULL);
		*tree = new_node;
		return (*tree);
	}
	head = *tree;
	if (head->n > value)
	{
		if (head->left)
			return (bst_insert(&head->left, value));

		new_node = binary_tree_node(head, value);
		if (!new_node)
			return (NULL);
		head->left = new_node;
		return (new_node);
	}

	if (head->n < value)
	{
		if (head->right)
			return (bst_insert(&head->right, value));

		new_node = binary_tree_node(head, value);
		if (!new_node)
			return (NULL);
		head->right = new_node;
		return (new_node);
	}
	return (NULL);
}
