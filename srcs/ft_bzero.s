section .text
	global	_ft_bzero

error:
	ret

_ft_bzero:
	test rdi, rdi
	je error
	mov rcx, rsi
	mov al, 0
	cld
	rep stosb
	ret
