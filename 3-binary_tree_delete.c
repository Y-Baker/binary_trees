#include "binary_trees.h"

void delete_recursion(binary_tree_t *node);
/**
*	binary_tree_delete - deletes an entire binary tree
*	@tree: root of tree
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	else 
		delete_recursion(tree);
}

void delete_recursion(binary_tree_t *node)
{
	if (!node)
		return;

	delete_recursion(node->left);
	delete_recursion(node->right);
	free(node);
}
