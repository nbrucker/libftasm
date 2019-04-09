section .text
	global _ft_strdup
	global _ft_test
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

_ft_strdup:
	push rbp
	mov rbp, rsp
	mov rbx, rdi		; save s1 addr
	call _ft_strlen		; call strlen
	mov r8, rax			; save strlen return in r8
	inc r8				; increment r8 for \0
	mov rdi, r8			; move len in rdi for malloc
	call _malloc		; call malloc
	mov r9, rax			; save malloc return in r9
	dec r8				; decrement r8 for memcpy
	mov rdi, r9			; move new addr in rdi for memcpy
	mov rsi, rbx		; move s1 in rsi for memcpy
	mov rdx, r8			; move len to rdx for memcpy
	call _ft_memcpy		; call memcy
	mov rax, r9			; move r9 to rax for ret
	leave				; clean
	ret					; return
