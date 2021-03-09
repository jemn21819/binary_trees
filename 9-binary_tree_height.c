#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of tree or 0 if is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t res;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	res = (max(binary_tree_height(tree->left),
					binary_tree_height(tree->right)) + 1);
	return (res);
}
