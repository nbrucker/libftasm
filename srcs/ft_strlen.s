section .text
	global _ft_strlen

error:
	mov rax, 0
	ret

_ft_strlen:
	test rdi, rdi
	je error
	mov rcx, 0
	not rcx
	mov al, 0
	cld
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx
	ret
