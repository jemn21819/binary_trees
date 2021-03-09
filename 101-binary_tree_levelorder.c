#include "binary_trees.h"
void _level(const binary_tree_t *tree, size_t level, void (*func)(int));

/**
 * _level - look for the level of the tree
 * @tree: pointer to the root node
 * @level: level of the tree
 * @func: pomter function
 */

void _level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		_level(tree->left, level - 1, func);
		_level(tree->right, level - 1, func);
	}
}

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
 * binary_tree_levelorder - goes through a binary
 * tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (!tree || !func)
		return;
	h = binary_tree_height(tree);
	for (i = 1; i <= h; i++)
		_level(tree, i, func);
}
