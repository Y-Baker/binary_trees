#include "binary_trees.h"
#include "9-binary_tree_height.c"
#include "113-bst_search.c"

void two_children(bst_t *node);
bst_t *inorder_successor(bst_t *tree);
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: the new root
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *to_remove, *tmp;

	if (root)
	{
		to_remove = bst_search(root, value);
		if (!to_remove)
			return (root);
		if (to_remove == root && !binary_tree_height(root))
		{
			free(root);
			return (NULL);
		}
		tmp = to_remove->parent;
		if (!to_remove->left && !to_remove->right)
		{
			if (tmp->left == to_remove)
				tmp->left = NULL;
			else
				tmp->right = NULL;
			free(to_remove);
			return (root);
		}
		if (to_remove->left && !to_remove->right)
		{
			if (!tmp)
				root = to_remove->left;
			if (tmp && tmp->left == to_remove)
				tmp->left = to_remove->left;
			else if (tmp && tmp->right == to_remove)
				tmp->right = to_remove->left;
			to_remove->left->parent = tmp;
			free(to_remove);
		}
		if (to_remove->right && !to_remove->left)
		{
			if (!tmp)
				root = to_remove->right;
			if (tmp && tmp->left == to_remove)
				tmp->left = to_remove->right;
			else if (tmp && tmp->right == to_remove)
				tmp->right = to_remove->right;
			to_remove->right->parent = tmp;
			free(to_remove);
		}
		if (to_remove->left && to_remove->right)
			two_children(to_remove);
	}
	return (root);
}


/**
 * inorder_successor - get the smallest number bigger than the left node
 * @tree: the bst to get the inorder_successor
 * Return: the inorder_successor
*/
bst_t *inorder_successor(bst_t *tree)
{
	if (tree)
	{
		while (tree->left)
			tree = tree->left;
	}
	return (tree);
}


/**
 * two_children - case of two childreb
 * @node: the node to remove
*/
void two_children(bst_t *node)
{
	bst_t *swap;

	swap = inorder_successor(node->right);

	node->n = swap->n;

	bst_remove(node->right, swap->n);
}
