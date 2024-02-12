;void ft_list_push_front(t_list **begin_list, void *data)
section .data
	extern malloc
	extern __errno_location

section .text
	global ft_list_push_front

ft_list_push_front:		;rdi -> begin_list ;rsi -> data
	push rsp
	push rdi
	push rsi
	mov rdi, 16
	xor rax, rax
	call malloc wrt ..plt
	cmp rax, 0
	je error_handler
	pop rsi
	pop rdi
	pop rsp
	mov [rax], rsi
	mov rcx, [rdi]
	mov [rax + 8], rcx
	mov [rdi], rax
	ret

error_handler:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, -1
	ret
