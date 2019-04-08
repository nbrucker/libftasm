section .text
	global _ft_strlen

loop:
	inc rax
	inc rdi
	cmp byte[rdi], 0
	jne loop
	ret

_ft_strlen:
	mov rax, 0
	cmp byte[rdi], 0
	jne loop
	ret
