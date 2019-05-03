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
	jc end

	mov r9, rax

	lea rsi, [rel buf]
	mov rdi, 1
	mov rdx, r9
	mov rax, 0x2000004
	syscall
	jc end

	cmp r9, 0
	jg reading

end:
	leave
	ret

section .bss
	buf resb 4097
