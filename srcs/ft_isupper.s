section .text
	global _ft_isupper

not_upper:
	mov rax, 0
	ret

_ft_isupper:
	cmp rdi, 65
	jl not_upper
	cmp rdi, 90
	jg not_upper
	mov rax, 1
	ret
