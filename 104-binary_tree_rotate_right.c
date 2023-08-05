#include "binary_trees.h"
/**
 * binary_tree_rotate_right - A function that performs
 * a right-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || !tree->left)
		return (tree);
	pivot = tree->left;
	tree->left = pivot->right;
	if (tree->left)
		tree->left->parent = tree;
	if (tree->parent)
	{
		if (tree->parent->right == tree)
			tree->parent->right = pivot;
		else
			tree->parent->left = pivot;
	}
	pivot->parent = tree->parent;
	pivot->right = tree;
	tree->parent = pivot;
	return (pivot);
}
