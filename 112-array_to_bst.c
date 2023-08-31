#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created BST, or NULL on failure
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i, tmp;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (tmp = 0; tmp < i; tmp++)
		{
			if (array[tmp] == array[i])
				break;
		}
		if (tmp == i) /*Loop Finish As Expected*/
		{
			if (!bst_insert(&root, array[i]))
			{
				return (NULL);
			}
		}
	}
	return (root);
}
