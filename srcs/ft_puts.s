section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp
	mov rsi, rdi		; string to print
	call _ft_strlen		; call strlen to get length
	mov rdi, 1			; stdout
	mov rdx, rax		; length to print
	mov rax, 0x2000004	; syscall write
	syscall
	leave
	ret					; return
