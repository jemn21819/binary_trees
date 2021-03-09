#include "binary_trees.h"

/**
 * binary_tree_depth -  measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: messure of depth or 0 if NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t res;

	if (!tree || !tree->parent)
		return (0);
	res = (binary_tree_depth(tree->parent) + 1);
	return (res);
}
