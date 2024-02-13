;int ft_list_size(t_list *begin_list)
section .text
	global ft_list_size

ft_list_size: ;rdi = begin_list
	xor rax, rax
	cmp rdi, 0
	je end_loop
	jmp size_loop

size_loop:
	inc rax
	cmp QWORD [rdi + 8], 0
	je end_loop
	mov rdi, [rdi + 8]
	jmp size_loop

end_loop:
	ret
