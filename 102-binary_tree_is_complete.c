#include "binary_trees.h"
/**
 * new_node - A function that adds a new_node in a linked_list
 * @node: pointer to the node to be created
 * Return: the node created
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new_n;

	new_n =  malloc(sizeof(link_t));
	if (!new_n)
	{
		return (NULL);
	}
	new_n->node = node;
	new_n->next = NULL;

	return (new_n);
}
/**
 * free_mem - function for freeing a linked list
 * @head: Pointer to the head of the linked list
 */
void free_mem(link_t *head)
{
	link_t *tmp_node;

	while (head)
	{
		tmp_node = head->next;
		free(head);
		head = tmp_node;
	}
}
/**
 * push_node - Function that pushes a node into the stack
 * @node: Pointer to the binary tree node
 * @head: Pointer to the head of the linked list
 * @tail: Double pointer to the tail of the linked list
 */
void push_node(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new;

	new = new_node(node);
	if (new == NULL)
	{
		free_mem(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}
/**
 * _pop -A f unction that pops a node into the stack
 * @head: pointer to head node of in the stack
 */
void _pop(link_t **head)
{
	link_t *tmp_node;

	tmp_node = (*head)->next;
	free(*head);
	*head = tmp_node;
}
/**
 * binary_tree_is_complete - Function that checks if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if is complete 0 if it is not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (!tree)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (!head)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_mem(head);
				return (0);
			}
			push_node(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_mem(head);
				return (0);
			}
			push_node(head->node->right, head, &tail);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}
