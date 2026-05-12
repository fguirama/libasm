extern _malloc
extern _ft_strlen
extern _ft_strcpy

section .text
global _ft_strdup

_ft_strdup:
    push rdi

    call _ft_strlen

    mov rdi, rax
    inc rdi
    call _malloc

    test rax, rax
    je .done

    mov rdi, rax
    pop rsi
    call _ft_strcpy

.done:
    ret
