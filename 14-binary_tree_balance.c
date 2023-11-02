#include "binary_trees.h"

/**
 * binary_tree_height_blc - Measures height of a binary tree
 * @tree: tree
 * Return: the height
 */

size_t binary_tree_height_blc(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
		left = tree->left ? 1 + binary_tree_height_blc(tree->left) : 1;
		right = tree->right ? 1 + binary_tree_height_blc(tree->right) : 1;
		}
		return ((left > right) ? left : right);
	}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree
 * Return: balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int r = 0, l = 0, total = 0;

	if (tree)
	{
		l = ((int)binary_tree_height_blc(tree->left));
		r = ((int)binary_tree_height_blc(tree->right));
		total = l - r;
	}
	return (total);
}
