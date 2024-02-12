section .text
	extern malloc
	extern ft_strlen
	global ft_strdup

ft_strdup:
	xor rax, rax
	mov rcx, rdi
	call ft_strlen
	call malloc wrt ..plt
	mov rdx, rax
	xor rax, rax
	jmp dup_loop

dup_loop:
	mov r8, [rcx + rax]
	mov [rdx + rax], r8
	cmp r8, byte 0
	jne dup_loop
	jmp exit_loop

exit_loop:
	mov rax, rdx
	ret
