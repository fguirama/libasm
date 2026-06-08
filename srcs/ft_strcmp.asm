section .text
global ft_strcmp

ft_strcmp:
    push cl
    xor rax, rax

.cmp_loop:
    cmp byte [rdi + rax], 0
    je .done

    movzx ecx, [rdi + rax]
    cmp ecx, [rsi + rax]
    jne .done
    inc rax
    jmp .cmp_loop

.done:
    movzx ecx, [rdi + rax]
    sub ecx, [rsi + rax]
    movzx rax, cl
    pop cl
    ret

;todo demander a chat gpt de tous m'expliquer
;todo test linux
;todo demander gentilement un audit par chat gpt