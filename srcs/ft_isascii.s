section .text
	global _ft_isascii

not_ascii:
	mov rax, 0
	ret

_ft_isascii:
	cmp rdi, 0
	jl not_ascii
	cmp rdi, 127
	jg not_ascii
	mov rax, 1
	ret
