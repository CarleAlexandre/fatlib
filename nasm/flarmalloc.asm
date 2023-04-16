
global _start

section .data
section .text

_sbrk:
	mov r0, #0 ; allocate 0 bytes
	mov r7, #45 ; sbrk system call number
	svc #0 ; call the sbrk system call
	mov r10, r0 ; store the returned pointer in r10

_start:
	call _sbrk
	mov	ebx, eax;
	// no i need to check if return is null
	// if null write error
	// else write sbrk ptr

