section .text
	global _ft_memset

error:
	mov rax, 0
	ret

_ft_memset:
	test rdi, rdi
	je error
	mov rbx, rdi
	mov rcx, rdx
	mov al, sil
	cld
	rep stosb
	mov rax, rbx
	ret
