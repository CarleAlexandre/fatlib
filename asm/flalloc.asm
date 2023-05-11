.global _start
.intel_syntax noprefix

_flalloc:
	push rbp
	mov rbp, rsp

	mov	rax, 12
	mov	rdi, 0
	syscall

	movq [brk_firslocation], rax

	lea	rdi, [rax + 5]
	mov rax, 12
	syscall
