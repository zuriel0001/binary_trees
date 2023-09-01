#include "binary_trees.h"

/**
 * insert_node_val - a function that does node value instertion in a AVL.
 *
 * @tree: double pointer of root node of the AVL tree struct.
 * @parent: pointer to parent node of struct AVL.
 * @new: double pointer left or right insertion.
 * @nval: insertion value of the AVL.
 *
 * Return: pointer to the new root otherwise NULL
 */
avl_t *insert_node_val(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int bval;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));
	if ((*tree)->n > nval)
	{
		(*tree)->left = insert_node_val(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = insert_node_val(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	bval = binary_tree_balance(*tree);
	if (bval > 1 && (*tree)->left->n > nval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval < -1 && (*tree)->right->n < nval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bval < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - a function that inserts a value in an AVL Tree
 *
 * @tree: double pointer 2 de root node of the AVL tree for inserting the value
 * @value: the value to store in the node to be inserted
 *
 * Return: inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_value = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert_node_val(tree, *tree, &new_value, value);
	return (new_value);
}
