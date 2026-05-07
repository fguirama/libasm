cmake_minimum_required(VERSION 3.20)
project(libasm C)
enable_language(C ASM_NASM)
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
add_executable(prog
        main.c
        srcs/ft_strlen.asm
)
