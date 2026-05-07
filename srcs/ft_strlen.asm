section .text
global _ft_strlen

_ft_strlen:
    xor rax, rax

.next_char:
    cmp byte [rdi + rax], 0
    je .done
    inc rax
    jmp .next_char

.done:
    ret
