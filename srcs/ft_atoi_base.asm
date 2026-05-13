extern ft_strlen

section .text
global ft_atoi_base

; ==== MAIN =====
ft_atoi_base:
    cmp rsi, 0
    je .error
    mov r12, rdi
    mov r13, rsi
    mov rdi, rsi
    call ft_strlen
    cmp rax, 1
    jle .error
    xor rcx, rcx

    mov rdi, r13
    mov rsi, '-'
    call strchr
    cmp rax, -1
    jne .error

    mov rdi, r13
    mov rsi, '+'
    call strchr
    cmp rax, -1
    jne .error

    ; " \t\n\v\f\r+-"

    ret

.error:
    xor rax, rax
    ret

; ==== find char =====
strchr:
.loop:
    mov al, byte [rdi]
    cmp al, sil
    je .found
    cmp al, 0
    je .not_found
    inc rdi
    jmp .loop

.found:
    mov rax, rdi
    ret

.not_found:
    mov rax, -1
    ret











.done:
    mov cl, byte [rdi + rax]
    sub cl, byte [rsi + rax]
    movsx rax, cl
    ret
