#include "binary_trees.h"

/**
 * binary_tree_insert_left - A function that inserts a node as the
 *                           left-child of another node
 *
 * @parent: a pointer to the node to insert the left-child in
 * @value: value of the node
 *
 * Description: If parent already has a left-child, the new node must take its
 * place, and the old left-child must be set as the left-child of the new node.
 *
 * Return: pointer to the created node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *lc_new_node;

	if (!parent)
	{
		return (NULL);
	}

	lc_new_node = binary_tree_node(parent, value);
	if (!lc_new_node)
	{
		return (NULL);
	}

	if (parent->left != NULL)
	{
		lc_new_node->left = parent->left;
		parent->left->parent = lc_new_node;
	}

	parent->left = lc_new_node;
	return (lc_new_node);
}
