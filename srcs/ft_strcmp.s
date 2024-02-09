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
	jmp ft_check_first_string

ft_check_first_string:
	cmp byte [rdi + rdx],0
	je ft_check_second_string
	jmp ft_loop

ft_check_second_string:
	cmp byte [rsi + rdx],0
	je end_loop
	jmp ft_loop

end_loop:
	movzx rax, cl
	ret
