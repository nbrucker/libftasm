section .text
	global _ft_isprint

not_print:
	mov rax, 0
	ret

_ft_isprint:
	cmp rdi, 32
	jl not_print
	cmp rdi, 126
	jg not_print
	mov rax, 1
	ret
