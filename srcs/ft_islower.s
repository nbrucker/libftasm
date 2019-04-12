section .text
	global _ft_islower

not_lower:
	mov rax, 0
	ret

_ft_islower:
	cmp rdi, 97
	jl not_lower
	cmp rdi, 122
	jg not_lower
	mov rax, 1
	ret
