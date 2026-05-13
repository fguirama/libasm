extern malloc
extern ft_strlen
extern ft_strcpy

section .text
global ft_strdup

ft_strdup:
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
    ret
