#include "binary_trees.h"

bst_t *insert(bst_t *root, int value);

/**
 * bst_insert - A function that inserts a value in a Binary Search Tree
 *
 * @tree: is a double pointer to the root node of the BST to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL,
 * the created node must become the root node.
 * If the value is already present in the tree, it must be ignored
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *root;

	if (!tree)
		return (NULL);
	root = *tree;
	if (!root)
	{
		root = binary_tree_node(NULL, value);
		*tree = root;
		return (root);
	}
	return (insert(root, value));
}

/**
 * insert - A helper funtion
 * it inserts a new node with @value into binary search tree @root
 * @root: root of binary search tree
 * @value: value for new node
 * Return: the inserted node on success, Null on failure
 * It returns Null if @value is in @root
 */
bst_t *insert(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	else if (value == root->n)
		return (NULL);
	else if (value < root->n)
	{
		if (!root->left)
		{
			root->left = binary_tree_node(root, value);
			return (root->left);
		}
		return (insert(root->left, value));
	}
	else
	{
		if (!root->right)
		{
			root->right = binary_tree_node(root, value);
			return (root->right);
		}
		return (insert(root->right, value));
	}
}
