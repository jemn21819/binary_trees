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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 for perfect 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int a, b, res;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	a = binary_tree_height(tree->left);
	b = binary_tree_height(tree->right);
	if (a != b)
		return (0);
	res = (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
	return (res);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if is complete and 0 if is not
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int res;
	binary_tree_t *l = tree->left;
	binary_tree_t *r = tree->right;
	size_t l_bp = binary_tree_is_perfect(l);
	size_t r_bp = binary_tree_is_perfect(r);
	size_t l_bc = binary_tree_is_complete(l);
	size_t r_bc = binary_tree_is_complete(r);

	if (!tree)
		return (0);
	if (binary_tree_is_perfect(tree))
		return (1);
	res = binary_tree_balance(tree);
	if (res == 0)
		return (l_bp && r_bc);
	if (res == 1)
		return (l_bc && r_bp);
	else
		return (0);
}
