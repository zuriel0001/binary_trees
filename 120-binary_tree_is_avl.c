#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: The height of thee tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((l > r) ? l : r);
		}
}

/**
 * bal_avl - Auxiliar function to compare each subtree if its AVL.
 *
 * @tree: pointer to the tree to check.
 * @high: pointer to the higher node selected
 * @lower: pointer to the lower node selected.
 *
 * Return: 1 if tree is AVL, 0 if not.
 */

int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t left_height, right_height, balancer;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);
		balancer = left_height > right_height ? left_height - right_height :
							right_height - left_height;
		if (balancer > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - a function that checks if a binary
 * tree is a valid AVL Tree
 *
 * @tree: pointer to node that point to the tree to check.
 *
 * Return: 1 if tree is AVL, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
