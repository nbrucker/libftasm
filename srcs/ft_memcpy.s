section .text
	global _ft_memcpy

_ft_memcpy:
	mov rbx, rdi
	mov rcx, rdx
	cld
	rep movsb
	mov rax, rbx
	ret
