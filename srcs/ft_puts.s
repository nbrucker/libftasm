section .data
	nl db "", 10
	null db "(null)", 10

section .text
	global _ft_puts
	extern _ft_strlen

empty:
	lea rsi, [rel null]
	mov rdi, 1
	mov rdx, 7
	mov rax, 0x2000004
	syscall
	jc error
	jmp success

_ft_puts:
	push rbp
	mov rbp, rsp

	test rdi, rdi
	je empty

	mov rsi, rdi		; string to print
	call _ft_strlen		; call strlen to get length
	mov rdi, 1			; stdout
	mov rdx, rax		; length to print
	mov rax, 0x2000004	; syscall write
	syscall

	lea rsi, [rel nl]
	mov rdi, 1
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	jc error
	jmp success

error:
	mov rax, -1
	leave
	ret

success:
	mov rax, 10
	leave
	ret
