section .text
	global _ft_memset

set:
	mov byte [rdi + rcx], 'g'
	inc rcx
	cmp rcx, rdx
	jne set
	ret


_ft_memset:
	mov rcx, 0
	mov rax, qword rdi
	cmp rcx, rdx
	jne set
	ret
