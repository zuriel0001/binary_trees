#include "binary_trees.h"
/**
 * successor - A function that gets the next successor minimum
 *             node in the right subtree
 *
 * @node: A pointer to the tree to check
 * Return: the mininum value of this tree
 */

int successor(bst_t *node)
{
	int left = 0;

	if (!node)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}

/**
 * two_children - A function that gets the next successor usi
 *
 * @root: pointer to node with two children
 *
 * Return: the the successor
 */
int two_children(bst_t *root)
{
	int new_value = 0;

	new_value = successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 *remove_type - A function that removes a node depending of its children
 *
 *@root: A pointer to node to be removed
 *
 * Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}

/**
 * bst_remove - A function that remove a node from a BST tree
 *
 * @root: A pointer to the root of the tree
 * @value: the value to remove in the tree
 *
 * Return: the tree changed
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (!root)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
	{
		return (NULL);
	}
	return (root);
}
