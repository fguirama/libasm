# ---------- VARIABLES ---------------------------------------------------------- #
NAME        =	libasm.a

SRCS_DIR    =	srcs/
OBJS_DIR    =	.objs/

SRCS        =	ft_strlen.asm \
             	ft_strcpy.asm \
             	ft_strcmp.asm
#             	ft_write.asm \
#             	ft_read.asm \
#             	ft_strdup.asm

SRCS        :=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS        :=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.asm=.o)))

CC          =	gcc
CFLAGS      =	-Wall -Wextra -Werror -g3 -fsanitize=address
NASM        =	nasm
NASMFLAGS   =	-f macho64
#NASMFLAGS   =	-f elf64
AR          =	ar rcs
RM          =	rm -rf

# ---------- RULES -------------------------------------------------------------- #
all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.asm
				@mkdir -p $(OBJS_DIR)
				$(NASM) $(NASMFLAGS) $< -o $@

run:			$(NAME)
				$(CC) $(CFLAGS) main.c -L. -lasm -o test
				./test

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME) test

re:				fclean all

.PHONY: all clean fclean re run
