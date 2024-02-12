;char		*ft_strdup(const char *s)
section .data
	extern malloc
	extern ft_strlen
	extern ft_strcpy
	extern __errno_location

section .text
	global ft_strdup

ft_strdup:
	xor rax, rax
	call ft_strlen
	inc rax
	mov r8, rdi
	mov rdi, rax
	call malloc wrt ..plt
	cmp rax, 0
	jl error_handler
	mov rdi, rax
	mov rsi, r8
	xor rax, rax
	call ft_strcpy
	ret

error_handler:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, -1
	ret
