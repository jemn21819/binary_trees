#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 or 0 for NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int a, b;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	a = (binary_tree_is_full(tree->left) == 1);
	b = (binary_tree_is_full(tree->right) == 1);
	if (a && b)
		return (1);
	return (0);
}