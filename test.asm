bits 64


section .data
    coucou: db "hey coucou", 10

section .bss
    read_buff: resb 64

section .text
    global _start
    _start:
        mov rax, 0x00
        mov rdi, 0
        mov rsi, read_buff
        mov rdx, 64
        syscall

        add rax, 48
        mov rsi, rax
        mov rax, 0x01
        mov rdi, 1
        mov rdx, 1
        syscall

        mov rax, 60
        mov rdi, 0
        syscall
