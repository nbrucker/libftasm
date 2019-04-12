section .text
	global	_ft_isalpha
	extern _ft_isupper
	extern _ft_islower

alpha:
	mov rax, 1
	ret

_ft_isalpha:
	call _ft_isupper
	cmp rax, 0
	jne alpha
	call _ft_islower
	cmp rax, 0
	jne alpha
	mov rax, 0
	ret
