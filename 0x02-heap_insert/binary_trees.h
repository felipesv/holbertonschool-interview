#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);

void heap_max(heap_t **pa, heap_t **nw, size_t ht, size_t sz,
	size_t mi, size_t comp);
size_t sizeHeightMiMxLv(heap_t *tree, size_t sh, size_t height);
size_t powR(size_t x, size_t y);
void changeParent(heap_t **new);


#endif /* _BINARY_TREES_H_ */
