section .text
	global	_ft_tolower
	extern _ft_isupper

change:
	add rdi, 32

_ft_tolower:
	call _ft_isupper
	cmp rax, 0
	jne change
	mov rax, rdi
	ret
