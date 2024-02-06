section .text

ft_strlen:
	mov rax, 0		; Inialize the return to 0
	jmp inc_Loop

inc_Loop:
	cmp byte [rdi + rax],0
	je end_loop
	inc rax
	jmp inc_Loop

end_loop:
	ret