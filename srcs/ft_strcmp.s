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
	je check_end
	jne end_loop

check_end:
	cmp byte [rdi + rdx],0
	je end_loop
	jmp ft_loop

end_loop:
	movzx rax, cl
	ret
