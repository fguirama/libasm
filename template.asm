bits 64

;system v amd
; rax = syscall number
; cl
; rdi, rsi, rdx, rcx, r8, r9 (pile de droite a gauche)
; retour dans rax | rax rbx


; 15d, 0d15
; 0q755, 755q
; 1001b, 0b1001
; 0xA15, BC41x

;b = bytes   8 bits 00000000 cl
;w = word   16 bits          cx
;d = d-word 32 bits          ecx
;q = q-word 64 bits          rcx

;movzx -> 00000000000000000000000
;movsx -> 0000000 et ca garde le signe

;t 80bits
;o 128bits
;y 256bits
;z 512bits

section .bss
    resX
    ; variable

section .data
    variable_name (label) : dX "DATA", 10 ; variable_name est un pointeur vers l'addresse memoire du message, pas le message lui meme (normale je peux stocker uniquement des int)
    lenght_string: equ $ - message ; $ = adresse courante - taille de la string (oblige de mettre juste apres)
    VARIABLENAME : equ 10 ; constante
    array: times 25 db 0 ; je declare 20 * db (1octet) 0
    ; constante

section .text
    global _start

    _start:
        mov rax, 1
        mov rdi, 1
        mov rsi, message
        mov rdx, 13+1
        syscall

        mov rax, 60
        mov rdi, 15
        syscall
