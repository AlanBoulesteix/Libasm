section .text
	global ft_strlen

ft_strlen:
	mov rax, 0		; Inialize the return to 0
	jmp inc_Loop	; Jump without condition

inc_Loop:
	cmp byte [rdi + rax],0	; Compare str[i] with '0' to see if we are at the end
	je end_loop				; je is for jump if comp return egal
	inc rax					; rax incrementation
	jmp inc_Loop			; jmp without condition

end_loop:
	ret						; return rax 