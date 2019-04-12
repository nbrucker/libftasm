section .text
	global	_ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

alnum:
	mov rax, 1
	ret

_ft_isalnum:
	call _ft_isalpha
	cmp rax, 0
	jne alnum
	call _ft_isdigit
	cmp rax, 0
	jne alnum
	mov rax, 0
	ret
