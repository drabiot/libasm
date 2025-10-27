section .text
global ft_strcpy

ft_strcpy:
.loop:
	mov al, [rsi]		;put src char into a 8-bits register
	mov [rdi], al		;put current 8-bits register into the dest 
	inc rsi				;increase src pointer
	inc rdi				;increase dest pointer
	test al, al			;check if the 8-bits register is null
	jne .loop			;continue if the 8-bits register is not null
	ret