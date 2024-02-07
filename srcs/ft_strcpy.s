;char *strcpy(char *dest, const char *src);

section .text
	global ft_strcpy

ft_strcpy:
	xor rax, rax
	jmp loop_copy
loop_copy:
	cmp byte [rsi + rax],0
	mov cl, [rsi + rax]
	mov [rdi + rax], cl
	je end_loop
	inc rax
	jmp loop_copy

end_loop:
	mov rax, rsi
	ret