#include "binary_trees.h"
/**
 * bst_search - function that searches for a value in a Binary Search Tree
 * @tree: is a pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 * Return: a pointer to the node containing a value equals to @value,
 * or NULL If tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	else if (value == tree->n)
		return ((bst_t *)tree);
	else if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
