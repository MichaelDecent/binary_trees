#include "binary_trees.h"
/**
 * array_to_bst - A function that builds a Binary Search Tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: a pointer to the root node of the created BST, or NULL on failure
 * If a value of the array is already present in the tree, the value is ignored
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root;

	if (!array || size == 0)
		return (NULL)
	root = NULL;
	i = 0;
	while (i < size)
	{
		bst_insert(&root, array[i]);
		i++;
	}
	return (root);
}
