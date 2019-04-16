section .text
	global	_ft_strcat
	extern _ft_strlen
	extern _ft_memcpy

error:
	mov rax, rbx
	ret

_ft_strcat:
	mov rbx, rdi
	test rdi, rdi
	je error
	test rsi, rsi
	je error
	call _ft_strlen
	mov r8, rax
	mov rdi, rsi
	call _ft_strlen
	mov rdx, rax
	mov rdi, rbx
	add rdi, r8
	call _ft_memcpy
	mov byte [rdi], 0
	mov rax, rbx
	sub rax, r8
	ret
