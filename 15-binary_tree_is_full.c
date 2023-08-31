#include "binary_trees.h"
/**
 * binary_tree_is_full - Function that checks if a binary tree is full
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 if it is a full 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
	{
		return (0);
	}
	else
	{
		if (tree->left && tree->right)
		{
			left = binary_tree_is_full(tree->left);
			right = binary_tree_is_full(tree->right);
			if (left == 0 || right == 0)
			{
				return (0);
			}
			return (1);
		}
		else if (tree->left == NULL && tree->right == NULL)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}
