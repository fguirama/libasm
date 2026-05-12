section .text
global _ft_strcmp

_ft_strcmp:
    xor rax, rax

.cmp_loop:
    cmp byte [rdi + rax], 0
    je .done

    mov cl, byte [rdi + rax]
    cmp cl, byte [rsi + rax]
    jne .done
    inc rax
    jmp .cmp_loop

.done:
    mov cl, byte [rdi + rax]
    sub cl, byte [rsi + rax]
    movsx rax, cl
    ret
