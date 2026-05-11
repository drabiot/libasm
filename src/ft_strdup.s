extern ft_strlen
extern ft_strcpy
extern malloc

section .text
global ft_strdup

ft_strdup:
	call	ft_strlen		;rax now have the length of src

	inc		rax				;add \0 in the return size
	push	rdi				;save src
	mov		rdi, rax		;make rdi have the same size as rax to malloc

	sub		rsp, 8			;align stack before call
	call	malloc WRT ..plt
	add		rsp, 8			;replace stack after call

	test	rax, rax		;check if rax is null
	jz		.error			;if rax is null it's an error

	mov		rdi, rax		;put malloc pointer in dest
	pop		rsi				;grab src adress
	call	ft_strcpy		;strcpy(dest, src)
	ret

.error
	pop		rdi				;clear the stack
	ret						;return null
