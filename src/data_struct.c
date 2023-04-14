/*
 * =====================================================================================
 *
 *       Filename:  data_struct.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/14/23 05:38:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fatmeat (), pathofyggdrasil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

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
