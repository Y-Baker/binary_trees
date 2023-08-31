#include "binary_trees.h"
#include "11-binary_tree_size.c"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 If tree is Perfect and is NULL return 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int i;

	int size = binary_tree_size(tree);

	if (size == 1)
		return (1);

	for (i = 1; i <= size + 1; i *= 2)
	{
		if (size + 1 == i)
			return (1);
	}
	return (0);
}
