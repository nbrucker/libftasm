section .text
	global _ft_strdup
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
	test rax, rax
	je end
	mov r9, rax			; save malloc return in r9
	dec r8				; decrement r8 for memcpy
	mov byte[r9+r8], 0	; \0 at the end
	mov rdi, r9			; move new addr in rdi for memcpy
	mov rsi, rbx		; move s1 in rsi for memcpy
	mov rdx, r8			; move len to rdx for memcpy
	call _ft_memcpy		; call memcpy
	mov rax, r9			; move r9 to rax for ret
end:
	leave				; clean
	ret					; return
