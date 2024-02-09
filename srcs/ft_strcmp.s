section .text
	global ft_strcmp

ft_strcmp:
	xor rdx, rdx
	jmp ft_loop

ft_loop:
	mov cl, byte [rdi + rdx]
	sub cl, byte [rsi + rdx]
	inc rdx
	cmp cl,0
	jne end_loop
	jmp ft_check_strings

ft_check_strings:
	cmp byte [rdi + rdx],0
	jne ft_loop
	cmp byte [rsi + rdx],0
	je end_loop
	jmp ft_loop

end_loop:
	movzx rax, cl
	ret
