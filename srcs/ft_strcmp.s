section .text
	global ft_strcmp
	global ft_strlen

ft_strcmp:
	xor rax,rax
	jmp ft_loop

ft_loop:
	mov cl, [rdi + rax]
	mov dl, [rsi + rax]
	sub cl,dl
	inc rax
	jne end_loop
	

end_loop:
	mov rax, cl
	ret

