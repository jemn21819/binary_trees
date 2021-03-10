#include "binary_trees.h"

/**
 * bst_left - verify the left node for value less tha val
 * @tree: node to comparete
 * @val: value to comparate
 * Return: 1 if nodes are less or 0 otherwise
 */

int bst_left(const binary_tree_t *tree, int val)
{
	int left, right;

	if (!tree)
		return (1);
	left = bst_left(tree->left, val);
	right = bst_left(tree->right, val);
	if (tree->n < val)
		return (left && right);
	return (0);
}

/**
 * bst_right - verify  right nodes are grater than value
 * @tree: node to compare
 * @val: value to compare
 * Return: 1 or 0 otherwise
 */

int bst_right(const binary_tree_t *tree, int val)
{
	int left, right;

	if (!tree)
		return (1);
	left = bst_right(tree->left, val);
	right = bst_right(tree->right, val);
	if (tree->n > val)
		return (right && left);
	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	left = binary_tree_is_bst(tree->left);
	right = binary_tree_is_bst(tree->right);
	if (bst_left(tree->left, tree->n) && bst_right(tree->right, tree->n))
		return ((!tree->left || left) && (!tree->right || right));
	return (0);
}
