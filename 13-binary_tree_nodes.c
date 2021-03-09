#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: counts, 0 or 1
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t a, b;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	a = binary_tree_nodes(tree->left);
	b = binary_tree_nodes(tree->right);
	return (a + b + 1);
}
