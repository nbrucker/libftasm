section .text
	global _ft_memcpy

error:
	mov rax, 0
	ret

_ft_memcpy:
	test rdi, rdi
	je error
	test rsi, rsi
	je error
	mov rbx, rdi
	mov rcx, rdx
	cld
	rep movsb
	mov rax, rbx
	ret
