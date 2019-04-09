section .text
	global _ft_memset

_ft_memset:
	mov rbx, rdi
	mov rcx, rdx
	mov al, sil
	cld
	rep stosb
	mov rax, rbx
	ret
