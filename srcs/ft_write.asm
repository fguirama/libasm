extern __errno_location

section .text
global ft_write

ft_write:
    mov rax, 0x1
    syscall
    cmp rax, 0
    jl .error
    ret

.error:
    neg rax
    mov rdi, rax
    add rdi, 8
    call __errno_location
    sub rdi, 8
    mov [rax], rdi
    mov rax, -1
    ret
