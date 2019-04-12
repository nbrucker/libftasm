section .text
	global	_ft_toupper
	extern _ft_islower

change:
	sub rdi, 32

_ft_toupper:
	call _ft_islower
	cmp rax, 0
	jne change
	mov rax, rdi
	ret
