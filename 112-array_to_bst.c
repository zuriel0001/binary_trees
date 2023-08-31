#include "binary_trees.h"
/**
 * array_to_bst - a function that builds a Binary
 *                Search Tree from an array
 *
 * @array: Pointer to the array of integers.
 * @size: he number of elements in the array.
 *
 * Return: BST tree from array
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *bst_root;

	bst_root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		if (i == 0)
		{
			bst_insert(&bst_root, array[i]);
		}
		else
		{
			bst_insert(&bst_root, array[i]);
		}
		i++;
	}
	return (bst_root);
}
