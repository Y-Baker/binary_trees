#include "binary_trees.h"
#include <limits.h>

int node_is_bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: return 1 if tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (node_is_bst(tree, INT_MIN, INT_MAX));
}


/**
 * node_is_bst - check node is valid
 * @tree: pointer to the root node of the tree to check
 * @min: the minimum number for the node
 * @max: the maximum number for the node
 * Return: return 1 if node is a valid BST, and 0 otherwise
*/
int node_is_bst(const binary_tree_t *tree, int min, int max)
{
	int is_bst = 1;

	if (tree->n < min || tree->n > max)
		return (0);

	if (tree->left)
		is_bst *= node_is_bst(tree->left, min, tree->n - 1);
	if (tree->right)
		is_bst *= node_is_bst(tree->right, tree->n + 1, max);

	return (is_bst);
}
