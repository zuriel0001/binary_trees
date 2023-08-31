#include "binary_trees.h"
/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 *
 * @tree:  a double pointer to the root node of the BST
 * @value: value to store in the node to be inserted
 *
 * Return: The BST tree
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *tmp;
	binary_tree_t *aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_t *)(*tree), value);
		new_node = (bst_t *)aux;
		*tree = new_node;
	}
	else
	{
		tmp = *tree;
		if (value < tmp->n)
		{
			if (tmp->left)
				new_node = bst_insert(&tmp->left, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)tmp, value);
				new_node = tmp->left = (bst_t *)aux;
			}
		}
		else if (value > tmp->n)
		{
			if (tmp->right)
				new_node = bst_insert(&tmp->right, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)tmp, value);
				new_node = tmp->right = aux;
			}
		}
		else
			return (NULL);
	}
	return (new_node);
}
