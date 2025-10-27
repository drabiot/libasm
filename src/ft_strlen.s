section .text
global ft_strlen

ft_strlen:
	mov rax, 0					;create a 64-bits register that will be our return value

.loop:
	cmp byte [rdi + rax], 0	;compare the byte located at address (dest + <our 64-bits regitser>) with \0
	je .done						;if the byte is \0 run .done
	inc rax						;increase our return value
	jmp .loop					;jump directly on .loop

.done:
   ret
