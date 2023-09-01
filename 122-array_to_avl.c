#include "binary_trees.h"

/**
 * array_to_avl - a function that builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: AVL tree from array
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	size_t j = 0;
	avl_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&root, array[i]) == NULL)
			{
				return (NULL);
			}
		}
		i++;
	}
	return (root);
}
