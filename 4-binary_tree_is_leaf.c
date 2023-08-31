#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node:pointer to the node to checks
 * Return:If node is NULL, return 0
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->right && !node->left)
		return (1);
	else
		return (0);
}
