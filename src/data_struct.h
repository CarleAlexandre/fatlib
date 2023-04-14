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
 * Basic Data Structur
 * here vec 2 3 and 4 are linear Vector not data vector, for this use Datavector type
 */

typedef struct s_Tnode	Tnode;
typedef struct s_Vec2	Vec2;
typedef struct s_Vec3	Vec3;
typedef struct s_Datavector	Datavector;
typedef struct s_Lnode	Lnode;
typedef struct s_Vec4	Vec4;
typedef struct s_Vec4	Quaternion;
typedef struct s_Vec4	Rgbacolor;

typedef unsigned int uint;

struct s_Tnode {
	void	*data;
	Tnode	*left;
	Tnode	*right;
};

struct	s_Vec2 {
	float	x, y;
};

struct	s_Vec3 {
	float	x, y, z;
};

/*a data vector is a linked list where every node are contiguous in memery, basically an simple array ...*/
struct	s_Datavector {
	void	*vector;
	uint	typesize;
	uint	size;
};

struct	s_Lnode {
	void	*data;
	Lnode	*next;
	Lnode	*prev;
};

struct	s_Vec4 {
	float	x, y, z, w;
};

#endif
