/*
 * =====================================================================================
 *
 *       Filename:  data_struct.h
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

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

/*
 * Data Struct
 * here vec 2 3 and 4 are linear Vector not data vector, for this use Datavector type
 */

typedef unsigned int uint32;
typedef short i16;
typedef unsigned short u16;
typedef float f32;
typedef int	i32;
typedef unsigned int u32;
typedef double f64;
typedef long long i64;
typedef unsigned long long u64;
typedef void *ptr;

typedef struct s_Tnode	Tnode;
typedef struct s_Vec2	Vec2;
typedef struct s_Vec3	Vec3;
typedef struct s_Datavector	Datavector;
typedef struct s_Lnode	Lnode;
typedef struct s_Vec4	Vec4;
typedef struct s_Vec4	Quaternion;
typedef struct s_Vec4	Rgbacolor;
typedef struct s_Vertex	Vertex;

struct	s_Vec2 {
	float	x, y;
};

struct	s_Vec3 {
	float	x, y, z;
};

struct	s_Vec4 {
	float	x, y, z, w;
};

struct	s_Vertex {
	float	x, y, z;
	float	r, g, b, a;
};

struct s_Tnode {
	ptr		data;
	Tnode	*left;
	Tnode	*right;
};

/*
 * DESCRIPTION
 *	create a new binary tree node from allocator and store data in it.
 *
 * RETURN
 *  return either null if allocation failed or a pointer to the created node
 * 
 * NOTE
 *  allocator if it failed need to send back null (like malloc, or else the return value is undifined in case of fail)
 * */
static Tnode
*flCreateTNode(ptr data, ptr(*allocator)(u32)) {
	Tnode	*node;

	node = (Tnode *)allocator(sizeof(Tnode));
	if (node == 0x00)
		return (0x00);
	node->left = 0x00;
	node->right = 0x00;
	node->data = data;
	return (node);
}

struct	s_Lnode {
	void	*data;
	Lnode	*next;
	Lnode	*prev;
};

/*
 * DESCRIPTION
 *	create a new linked list node from allocator and store data in it.
 *
 * RETURN
 *  return either null if allocation failed or a pointer to the created node
 * 
 * NOTE
 *  allocator if it failed need to send back null (like malloc, or else the return value is undifined in case of fail)
 * */
static Lnode
*flCreateLNode(ptr data, ptr(*allocator)(u32)) {
	Lnode	*node;

	node = (Lnode *)allocator(sizeof(Lnode));
	if (node == 0x00)
		return (0x00);
	node->prev = 0x00;
	node->next = 0x00;
	node->data = data;
	return (node);
}

struct	s_Datavector {
	ptr	pointer;
	ptr	iterator;
	ptr	(*allocator)(u32);
	i32	(*add)(ptr);
	i32	(*del)(u32);
	u32	typesize;
	u32	size;
};

/*
 * DESCRIPTION
 *	create a new Data vector from allocator, and create a memory array of (size * typesize),
 *	assign a add and del function to allocator struct.
 *
 *	add function pointer should return an i32 (signed int) and take a ptr (void *) arguments.
 *	del function pointer should return an i32 (signed int) and take a u32 (unsigned int) arguments.
 *
 * RETURN
 *  return either null if allocation failed or a pointer to the created vector struct
 * 
 * NOTE
 *  allocator if it failed need to send back null (like malloc, or else the return value is undifined in case of fail)
 * */
static	Datavector
*new_vector(u32 typesize, u32 size, ptr(*allocator) (u32), i32(*del)(u32), i32(*add)(ptr)) {
	Datavector *vecteur;

	vecteur = (Datavector *)allocator(sizeof(Datavector));
	if (vecteur == 0x00)
		return (0x00);
	vecteur->pointer = allocator(typesize * size);
	if (vecteur->pointer == 0x00)
		return (0x00);
	vecteur->allocator = allocator;
	vecteur->typesize = typesize;
	vecteur->size = size;
	vecteur->iterator = vecteur->pointer;
	vecteur->add = add;
	vecteur->del = del;
	return (vecteur);
}

#endif

