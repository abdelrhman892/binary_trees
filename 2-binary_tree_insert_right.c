#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *
 * Description: If parent already has a right-child, the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *n;

	if (parent == NULL)
		return (NULL);

    n = binary_tree_node(parent, value);
	if (n == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
        n->right = parent->right;
		parent->right->parent = n;
	}
	parent->right = n;

	return (n);
}
