#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 *pow_recursion - returns the value x^y
 *@x: exponentiate
 *@y: power to raise x
 *Return: x to the power of y, -1 if y negative
 */


int pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * pow_recursion(x, y - 1));

}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree
 *
 * Return: 1 if the tree is perfect 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0;
	size_t n = 0;
	size_t power = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	h = binary_tree_height(tree);
	n = binary_tree_size(tree);

	power = (size_t)pow_recursion(2, h + 1);
	return (power - 1 == n);
}

