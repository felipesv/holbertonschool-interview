#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_node - create a new node
 *
 * @parent: Pointer to parent of the new node
 * @value: value of the new node
 *
 * Return: new node inserted
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
