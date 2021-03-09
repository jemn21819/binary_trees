#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of tree or 0 if is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t res;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (tree->parent != NULL);
	res = (max(binary_tree_height(tree->left),
				binary_tree_height(tree->right)) + 1);
	return (res);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to
 * measure the balance factor
 * Return: mesure or 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int a, b;

	if (!tree)
		return (0);
	a = binary_tree_height(tree->left);
	b = binary_tree_height(tree->right);
	return (a - b);
}
