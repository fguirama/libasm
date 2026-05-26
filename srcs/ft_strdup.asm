extern malloc
extern ft_strlen
extern ft_strcpy

section .text
global ft_strdup

ft_strdup:
    push r12
    push rdi
    push rsi
    mov r12, rdi

    call ft_strlen

    mov rdi, rax
    inc rdi
    call malloc

    test rax, rax
    je .done

    mov rdi, rax
    mov rsi, r12
    call ft_strcpy

.done:
    pop rsi
    pop rdi
    pop r12
    ret
