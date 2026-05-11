section .text
global ft_strcpy

ft_strcpy:
	mov	rax, rdi		;save adress of the start of dest in rax to return it at the end
.loop:
	mov dl, [rsi]		;put src char into a 8-bits register
	mov [rdi], dl		;put current 8-bits register into the dest 
	inc rsi				;increase src pointer
	inc rdi				;increase dest pointer
	test dl, dl			;check if the 8-bits register is null
	jne .loop			;continue if the 8-bits register is not null
	ret