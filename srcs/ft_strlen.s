section .text
	global _ft_strlen

_ft_strlen:
	mov rcx, 0
	not rcx
	mov al, 0
	cld
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx
	ret
