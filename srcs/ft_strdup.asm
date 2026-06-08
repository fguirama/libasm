extern malloc
extern ft_strlen
extern ft_strcpy

section .text
global ft_strdup

ft_strdup:
    push rbx
    mov rbx, rdi

    call ft_strlen

    mov rdi, rax
    inc rdi
    call malloc

    test rax, rax
    je .done

    mov rdi, rax
    mov rsi, rbx
    call ft_strcpy

.done:
    pop rbx
    ret
