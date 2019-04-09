section .text
	global _ft_isdigit

not_digit:
	mov rax, 0
	ret

_ft_isdigit:
	cmp rdi, 48
	jl not_digit
	cmp rdi, 57
	jg not_digit
	mov rax, 1
	ret
