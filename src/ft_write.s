extern __errno_location

section .text
global ft_write

ft_write:
	mov		rax, 1					;set rax to 1 for the sys_write
	syscall

	cmp		rax, 0					;verify syscall return
	jl		.error					;if rax < 0 it's an error
	ret								;else return readen bytes

.error:
	neg		rax						;make rax postive after syscall make him negative
	mov		rdi, rax				;copy return error
	push	rdi						;saves the error code and aligns the stack to 16 bytes to safely call a C library function
	call __errno_location WRT ..plt
	pop		rdi
	mov		[rax], rdi				;put return error in the pointed adress of rax
	mov 	rax, -1					;return -1 in case of an error
	ret
	