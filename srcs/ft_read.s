section .data
	extern __errno_location

section .text

	global ft_read

ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jl error_handler
	ret

error_handler:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, -1
	ret