section .text
global ft_strcmp

ft_strcmp:
.loop:
	mov al, [rdi]		;put dest char into a 8-bits register
	mov dl, [rsi]		;put src char int0 a 8-bits register
	cmp al, dl			;compare dest and src byte
	jne .diff			;if the byte isn't equal jump to .diff
	test al, al			;check if the 8-bits register is null
	je .equal			;if the byte is null jump to equal
	inc rdi				;increase dest pointer
	inc rsi				;increase src pointer
	jmp .loop			;jump directly on .loop

.diff:
	movzx eax, al		;move with zero-extend src 8-bits register into a 32-bits register
	movzx	edx, dl		;move with zero-extend dest 8-bits register into a 32-bits register
	sub eax, edx		;substract src with dest byte
	ret

.equal:
	xor eax, eax		;create a 32-bits register that will be our int return value
							;replace mov eax, 0
							;faster for the CPU - 2 bytes against 5 bytes instruction
	ret
