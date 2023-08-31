#include "binary_trees.h"
/**
 * check_left_subtree - Check if the binary tree is a valid left subtree.
 *
 * @node: Pointer to the root of the subtree to be checked
 * @max: The maximum value that all nodes in the subtree must be smaller than.
 *
 * Return: 1 if the subtree is a valid left subtree, 0 otherwise.
 */
int check_left_subtree(const binary_tree_t *node, int max)
{
	int left = 0, right = 0;

	if (!node)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);

		left = check_left_subtree(node->left, max);
		right = check_left_subtree(node->right, max);

		if (left == right && left == 1)
			return (1);

		return (0);
	}
}
/**
 * check_right_subtree - Check if the binary tree is a valid right subtree.
 *
 * @node: Pointer to the root of the subtree to be checked.
 * @min: The minimum value that all nodes in the subtree must be greater than.
 *
 * Return: 1 if the subtree is a valid right subtree, 0 otherwise.
 */
int check_right_subtree(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (!node)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = check_right_subtree(node->left, min);
		right = check_right_subtree(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * binary_tree_is_bst - a function that checks if a binary tree is a
 *                      valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if it is a BST or 0 if not
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int valid_subtree = 0;
	int left = 2, right = 2;

	if (!tree)
		return (0);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n < tree->n)
		return (0);

	if (tree->left && tree->left->n < tree->n)
	{
		valid_subtree = check_left_subtree(tree->left, tree->n);
		if (valid_subtree == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		valid_subtree = check_right_subtree(tree->right, tree->n);
		if (valid_subtree == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
