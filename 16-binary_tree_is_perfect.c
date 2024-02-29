#include "binary_trees.h"

unsigned char is_le_af(const binary_tree_t *node);
size_t depthOf(const binary_tree_t *tree);
const binary_tree_t *get_le_af_of(const binary_tree_t *tree);
int isPerfectRecursive(const binary_tree_t *tree,
                       size_t leaf_depth, size_t level);
int binaryTreeIsPerfect(const binary_tree_t *tree);

/**
 * is_le_af - Checks if.
 * @node: A pointer.
 *
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char is_le_af(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Returns the depthOf of a given
 *
 * @tree: A pointer.
 *
 * Return: The depthOf of node.
 */
size_t depthOf(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depthOf(tree->parent) : 0);
}

/**
 * get_le_af_of - Returns a leaf of a binary tree.
 * @tree: A pointer.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_le_af_of(const binary_tree_t *tree)
{
	if (is_le_af(tree) == 1)
		return (tree);
	return
    (tree->left ? get_le_af_of(tree->left) : get_le_af_of(tree->right));
}

/**
 * isPerfectRecursive - Checks if.
 * @tree: A pointer.
 * @leaf_depth: The depthOf of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int isPerfectRecursive(const binary_tree_t *tree,
                       size_t leaf_depth, size_t level)
{
	if (is_le_af(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (isPerfectRecursive(tree->left, leaf_depth, level + 1) &&
            isPerfectRecursive(tree->right, leaf_depth, level + 1));
}

/**
 * binaryTreeIsPerfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binaryTreeIsPerfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (isPerfectRecursive(tree, depthOf(get_le_af_of(tree)), 0));
}
