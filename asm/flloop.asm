; define var in data section
section .data
	result: db "NOOOOO", 10
section .text
	global _start

_start:
	call _draw;
	; terminate programme
	mov eax, 1; exit syscall
	mov ebx, 0; exit code of 0
	int 80h; call the kernel again

_draw:
	mov	eax, 4; write syscall == 4
	mov ebx, 1; file descriptor == 1 for stdout
	mov ecx, result; string to write
	mov edx, 1; string len
	int 80h; call the kernel
	jne _draw;
	ret
