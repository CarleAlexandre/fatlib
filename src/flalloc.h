/*
 * =====================================================================================
 *
 *       Filename:  flalloc.h
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
#include <sys/mman.h>
/*
this only work under linux, but should help me understand memory maping for a start

void	*flMemAlloc(uint size) {
	void	*ptr = 0x00;

	if (size == 0)
		return (ptr);
	ptr = mmap(0x00, size, PROT_NONE, MAP_PRIVATE, int fd, __off_t offset);
	mlock(const void *addr, size_t len);
	return (ptr);
}

void	flMemFree(void *ptr) {
	munlock(const void *addr, size_t len);
	munmap(void *addr, size_t len);
}

*/
