extern __errno_location

section .text
global ft_read

ft_read:
	xor	rax, rax 			;set rax to 0 for the sys_read
	syscall

	cmp	rax, 0				;verify syscall return
	jl	.error				;if rax < 0 it's an error
	ret						;else return readen bytes

.error:
	neg	rax					;make rax postive after syscall make him negative
	mov	rdi, rax			;copy return error
	call __errno_location	;grab errno adress in rax
	mov	[rax], rdi			;put return error in the pointed adress of rax
	mov rax, -1				;return -1 in case of an error
	ret
