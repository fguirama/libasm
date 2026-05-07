section .text
global _ft_strlen

_ft_strlen:
    mov rax, rdi

loop_mon_cul:
    cmp [rax], 0
    je end_of_program
    add rax, 1
    jmp loop_mon_cul

end_of_program:
    sub rax, rdi
    ret
