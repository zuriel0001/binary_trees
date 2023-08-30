#include "binary_trees.h"
/**
 * binary_tree_delete - A function that deletes an entire binary tree
 *
 * @tree: tree to free
 *
 * Description: If tree is NULL, do nothingIf tree is NULL, do nothing
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
		}
		free(tree);
	}

}
