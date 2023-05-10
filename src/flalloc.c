/*
 * =====================================================================================
 *
 *       Filename:  flalloc.c
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

#include <sys/mman.h>
#include <signal.h>


/*
 *	should look into brk and setrlimit,
 *	need to allocate memory to process before i map it ... smh,
 *	i really need to read more the manual sometime.
 * */

/*
this only work under linux, but should help me understand memory maping for a start
for now i'll keep using malloc on other part of the libs
 * */
void	*flMemAlloc(unsigned int size) {
	void	*ptr = 0x00;

	if (size == 0)
		return (ptr);
	ptr = mmap(0x00, size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!ptr) {
		return (0x00);
	}
	if (0 != mlock(ptr, size)) {
		munmap(ptr, size);
		return (0x00);
	}
	return (ptr);
}

//i need to understand how can i get back the size of a mapped and locked memory segment
void	flMemFree(void *ptr) {
	if (0 != munlock(ptr, 0) || 0 != munmap(ptr, 0))
		raise (SIGSEGV);
}

