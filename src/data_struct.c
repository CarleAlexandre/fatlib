#include "data_struct.h"
#include <stdlib.h>

Tnode	*flCreateNode(void *data) {
	Tnode	*node;

	node = (Tnode *)malloc(sizeof(Tnode));
	node->left = 0x00;
	node->right = 0x00;
	node->data = data;
	return (node);
}

Lnode	*flCreateLNode(void) {
	Lnode	*node;

	node = (Lnode *)malloc(sizeof(Lnode));
	
	return (node);
}
