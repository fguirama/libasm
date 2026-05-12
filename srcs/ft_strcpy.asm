section .text
global _ft_strcpy

_ft_strcpy:
    xor rax, rax

.cpy_loop:
    mov cl, byte [rsi + rax]
    mov [rdi + rax], cl
    cmp byte [rsi + rax], 0
    je .done
    inc rax
    jmp .cpy_loop

.done:
    mov rax, rdi
    ret
