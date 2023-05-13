/*
 * =====================================================================================
 *
 *       Filename:  flcall_linux.h
 *
 *    Description:  Linux Syscall single header library
 *
 *        Version:  1.0
 *        Created:  05/12/23 13:50:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fatmeat (), pathofyggdrasil@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

static void
flAbort(void) {
	__asm__(
	"movl $39, %%eax\n"
	"syscall\n"
	"movq %%rax, %%rdi\n"
	"movl $62, %%eax\n"
	"movq $6, %%rsi\n"
	"syscall\n"
	:::"rdi", "rsi"
	);
}

static void
flExit(unsigned int code) {
	__asm__(
	"movl %0, %%edi\n"
	"movl $60, %%eax\n"
	"syscall\n"
	::"r"(code)
	:"edi"
	);
}

static unsigned long
flWrite(unsigned int fd, char *restrict format, unsigned int nbytes) {
	unsigned long ret;

	__asm__(
	"movl $1, %%eax\n"
	"movl %1, %%edi\n"
	"movq %2, %%rsi\n"
	"movl %3, %%edx\n"
	"syscall\n"
	"movq %%rax, %0"
	:"=r"(ret)
	:"r"(fd), "r"(format), "r"(nbytes)
	:"rdi", "rsi", "rdx"
	);
	return (ret);
}

static int
flOpen(const char *filename, int flags, int mode) {
	int fd = 0;

	__asm__(
	"movl $2, %%eax\n"
	"movq %1, %%rdi\n"
	"movl %2, %%esi\n"
	"movl %3, %%edx\n"
	"syscall\n"
	"movl %%eax, %0\n"
	:"=r"(fd)
	:"r"(filename), "r"(flags), "r"(mode)
	:"rdi", "rsi", "rdx"
	);
	return (fd);
}

static int
flClose(int fd) {
	int ret = 0;

	__asm__(
	"movl $3, %%eax\n"
	"movl %1, %%edi\n"
	"syscall\n"
	"movl %%eax, %0"
	:"=r"(ret)
	:"r"(fd)
	:"edi"
	);
	return (ret);
}


static int
flRead(unsigned int fd, const char *buffer, unsigned int nbytes) {
	unsigned long ret;

	__asm__(
	"movl $0, %%eax\n"
	"movl %1, %%edi\n"
	"movq %2, %%rsi\n"
	"movl %3, %%edx\n"
	"syscall\n"
	"movq %%rax, %0"
	:"=r"(ret)
	:"r"(fd), "r"(buffer), "r"(nbytes)
	:"rdi", "rsi", "rdx"
	);
	return (ret);
}

