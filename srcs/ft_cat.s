section .text
	global	_ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp
	mov r8, rdi

reading:
	mov rdi, r8
	lea rsi, [rel buf]
	mov rdx, 4096

	mov rax, 0x2000003	; syscall read
	syscall

	mov r9, rax

	lea r10, [rel buf]
	add r10, r9
	mov byte [r10], 0

	lea rsi, [rel buf]
	mov rdi, 1
	mov rdx, r9
	mov rax, 0x2000004
	syscall

	cmp r9, 0
	jne reading

	leave
	ret

section .bss
	buf resb 4097
