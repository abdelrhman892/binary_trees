#include "binary_trees.h"

/**
 * binary_tree_balance - Measures.
 * @tree: A pointer.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height
        (tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures.
 * @tree: A pointer.
 *
 * Return: If.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t v = 0, x = 0;

        v = tree->left ? 1 + binary_tree_height(tree->left) : 1;
        x = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((v > x) ? v : x);
	}
	return (0);
}
