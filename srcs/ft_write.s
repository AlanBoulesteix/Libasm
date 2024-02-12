;ssize_t		ft_write(int fd, void *buf, size_t count)
section .data
	extern __errno_location

section .text
	global ft_write

ft_write: ;rdi = int fd , rsi = char *buf, rdx = size_t len
	mov rax, 1
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