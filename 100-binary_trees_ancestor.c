#include "binary_trees.h"

/**
 * binary_trees_ancestor - Function that finds the lowest common
 * ancestor of two nodes
 * @first: A pointer to the First node
 * @second: A pointer to the Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *i, *j;

	if (!first || !second)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	i = first->parent;
	j = second->parent;
	if (i == NULL || first == j || (!i->parent && j))
	{
		return (binary_trees_ancestor(first, j));
	}
	else if (j == NULL || i == second || (!j->parent && i))
	{
		return (binary_trees_ancestor(i, second));
	}
	return (binary_trees_ancestor(i, j));
}
