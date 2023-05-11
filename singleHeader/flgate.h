/*
 * =====================================================================================
 *
 *       Filename:  flgate.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/23 09:56:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fatmeat (), pathofyggdrasil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef FLGATE_H
# define FLGATE_H

/* this file exist juste for the fun of in 
 * you shouldn't use file
 * */

static int
buffer(int a) {
	return (a);
}

static int
flnot(int a) {
	return (!a);
}

static int
fland(int a, int b) {
	return (a && b);
}

static int
flor(int a, int b) {
	return (a || b);
}

static int
flnand(int a, int b) {
	return (!(a && b));
}

static int
flnor(int a, int b) {
	return (!a && !b);
}

static int
flxor(int a, int b) {
	return ((a && !b) || (!a && b));
}

static int
flxnor(int a, int b) {
	return ((a && b) || (!a && !b));
}

static int
flnandnot(int a) {
	return (flnand(a, a));
}

static int
flnandand(int a, int b) {
	int c = flnand(a, b);
	return (flnand(c, c));
}

static int
flnandnand(int a, int b) {
	return (flnand(a, b));
}

static int
flnandor(int a, int b) {
	return (flnand(flnand(a, a), flnand(a, b)));
}

static int
flnandnor(int a, int b) {
	int c = flnand(flnand(a, a), flnand(a, b));
	return (flnand(c, c));
}

static int
flnandxor(int a, int b) {
	int c = flnand(a, b);
	return (flnand(flnand(a, c), flnand(c , b)));
}

static int
flnandxnor(int a, int b) {
	int c = flnand(a, b);
	int d = flnand(flnand(a, c), flnand(c, b));
	return (flnand(d, d));
}

#endif
