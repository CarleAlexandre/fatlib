/*
 * =====================================================================================
 *
 *       Filename:  flmem.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/01/23 22:44:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fatmeat (), pathofyggdrasil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef FLMEM_H
# define FLMEM_H

/*
 *	DESCRIPTION
 *		the function copy n bytes of memory from src to dest 
 *	RETURN VALUE
 *		return dest pointer
 * */
static void
*flMemCpy(void *restrict dest, const void *restrict src, unsigned int n) {
	while (n--) {
		*(char*)(dest + n) = *(char *)(src + n);
	}
	return (dest);
}

/*
 *	DESCRIPTION
 *		the function copy n bytes of memory from src to dest.
 *	RETURN VALUE
 *		returns a pointer to the memory area (dest + n).
 *
 * */
static void
*flMemPCpy(void *restrict dest, const void *restrict src, unsigned int n) {
	for (int i = 0; i < n; i++) {
		*(char*)(dest + i) = *(char *)(src + i);
	}
	return (dest + n);
}

/*
 *	DESCRIPTION
       The  function fills the first n bytes of the memory area pointed to by mem with
       the constant byte b.

	RETURN VALUE
       The function returns a pointer to the memory area s.
 * */
static void
*flMemSet(void *restrict mem, int b, unsigned int n) {
	for (int i = 0; i < n; i++) {
		*(char *)(mem + i) = b;
	}
	return (mem);
}

#ifdef _WIN32

static void
flabort(void) {
	exit();
};

#endif

#ifdef __unix

static void
flabort(void) {
	__asm__(
	"movl $39, %eax\n"
	"syscall\n"
	"movq %rax, %rdi\n"
	"movl $62, %eax\n"
	"movq $6, %rsi\n"
	"syscall\n"
	);
}

static void
flexit(unsigned int code) {
	asm volatile(
	"movl %0, %%edi\n"
	"movl $60, %%eax\n"
	"syscall\n"
	::"a"(code)
	);
}

#endif

/*
 *	DESCRIPTION
 *		allocate a new memory chunk of n bytes and copy n byte of mem to new chunk
 *	RETURN VALUE
 *		return the new memory chunk
 *
 *	note
 *		need stdlib.h for malloc function
 *
 *		if you want to use this function you need to define FL_USE_STDLIB_DEP before the include
 * */
static void
*flMemDup(const void *mem, unsigned int n, void*(*allocator)(unsigned int)) {
	void	*dup;

	dup = allocator(n);
	while (n--) {
		*(char*)(dup + n) = *(char *)(mem + n);
	}
	return (dup);	
}

/*
 *	GNU libc strlen
 * */
static unsigned int
gStrLen(const char *str) {
	const char *char_ptr;
	const unsigned long int *longword_ptr;
	unsigned long int longword, himagic, lomagic;
	/* Handle the first few characters by reading one character at a time.
		Do this until CHAR_PTR is aligned on a longword boundary.  */
	for (char_ptr = str; ((unsigned long int) char_ptr
		& (sizeof (longword) - 1)) != 0; ++char_ptr)
		if (*char_ptr == '\0')
			return char_ptr - str;
	/* All these elucidatory comments refer to 4-byte longwords,
		but the theory applies equally well to 8-byte longwords.  */
	longword_ptr = (unsigned long int *) char_ptr;
	/* Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
		the "holes."  Note that there is a hole just to the left of
		each byte, with an extra at the end:
		bits:  01111110 11111110 11111110 11111111
		bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD
		The 1-bits make sure that carries propagate to the next 0-bit.
		The 0-bits provide holes for carries to fall into.  */
	himagic = 0x80808080L;
	lomagic = 0x01010101L;
	if (sizeof (longword) > 4) {
		/* 64-bit version of the magic.  */
		/* Do the shift in two steps to avoid a warning if long has 32 bits.  */
		himagic = ((himagic << 16) << 16) | himagic;
		lomagic = ((lomagic << 16) << 16) | lomagic;
	}
	if (sizeof (longword) > 8)
		flabort ();
	/* Instead of the traditional loop which tests each character,
		we will test a longword at a time.  The tricky part is testing
		if *any of the four* bytes in the longword in question are zero.  */
	for (;;) {
		longword = *longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic) != 0) {
			/* Which of the bytes was the zero?  If none of them were, it was
				a misfire; continue the search.  */
			const char *cp = (const char *) (longword_ptr - 1);
			if (cp[0] == 0)
				return cp - str;
			if (cp[1] == 0)
				return cp - str + 1;
			if (cp[2] == 0)
				return cp - str + 2;
			if (cp[3] == 0)
				return cp - str + 3;
			if (sizeof (longword) > 4) {
				if (cp[4] == 0)
					return cp - str + 4;
				if (cp[5] == 0)
					return cp - str + 5;
				if (cp[6] == 0)
					return cp - str + 6;
				if (cp[7] == 0)
					return cp - str + 7;
			}
		}
    }
}
# endif

