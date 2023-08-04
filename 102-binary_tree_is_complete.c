#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void check_level(const binary_tree_t *tree, size_t level, size_t *flag);

/**
 * binary_tree_is_complete - A function that checks
 * if a binary tree is complete
 *
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if @tree is complete, 0 if tree is NULL or not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height, level, flag;

	if (!tree)
		return (0);
	height = binary_tree_height(tree);
	flag = 'p';
	level = 0;
	while (level <= height && flag != 'f')
	{
		check_level(tree, level, &flag);
		level++;
	}
	if (flag == 'f')
		return (0);
	return (1);
}

/**
 * check_level - An helper function to check if @tree is a complete binary tree
 * @tree: the binary tree
 * @level: level of @tree
 * @flag: pointer to a size_t variable. It keeps
 * track of previous nodes visited
 */
void check_level(const binary_tree_t *tree, size_t level, size_t *flag)
{
	if (*flag == 'f')
		return;
	if (!tree)
	{
		*flag = 'a';
	}
	else if (level == 0)
	{
		if (*flag == 'a')
		{
			*flag = 'f';
		}
	}
	else
	{
		check_level(tree->left, level - 1, flag);
		check_level(tree->right, level - 1, flag);
	}
}
/**
 * binary_tree_height - An helper function
 * that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * If tree is NULL, the function returns 0
 * Return: height of @tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);
	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
