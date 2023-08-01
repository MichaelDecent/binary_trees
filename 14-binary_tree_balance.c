#include "binary_trees.h"

/**
 * binary_tree_balance - a function that measures the balance
 * factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (+0);
	if (tree->left == NULL || tree->right == NULL)
		return (-1);
	return (+2);
}
