#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes.
 * @tree: A pointer.
 *
 * Return: If tree is NULL, the function must return 0, else return node count
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t n = 0;

	if (tree)
	{
        n += (tree->left || tree->right) ? 1 : 0;
        n += binary_tree_nodes(tree->left);
        n += binary_tree_nodes(tree->right);
	}
	return (n);
}
