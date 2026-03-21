
# VAR ---------------------------------------------------------------
OBJS_DIR		=	.OBJS/
SRCS			=	test.asm
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.asm=.o))

NAME			=	libasm.a
HEAD			=	INCLUDES/

FLAGS			=	-f elf64
RM				=	rm -rf


# RULES ---------------------------------------------------------------------- #
all:				$(NAME)

run:				all
					./$(NAME)

bonus:
					$(NAME)

$(NAME):			$(OBJS)
					ld $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o:		%.asm
					@mkdir -p $(OBJS_DIR)
					nasm $(FLAGS) $< -o $@

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all run clean fclean re
