
NAME=ft_ls
LOGIN_AUTHOR=sle-guil
DEBUG=yes

CC = clang
C_FLAG = -Wall -Wextra -Werror -pipe

ifeq ($(DEBUG), yes)
OPT_FLAG = -O0 -g3
else
OPT_FLAG = -DNDEBUG -Os -g0 -march=native
endif

HEADER=incl
LIBFT=./libft
SRCS_NAME=	ft_error.c		ft_ls.c		main.c		s_opt.c

SRCS = $(addprefix srcs/,$(SRCS_NAME))
OBJS = $(SRCS:.c=.o)


#===============================#
#		Compilation rules 		#
#===============================#

all: $(NAME)

$(NAME): libft $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT) -I $(HEADER)
	@echo "$(NAME) created and indexed"
	@echo "*** Flag : $(OPT_FLAG) ***"

%.o: %.c
	@$(CC) -o $@ -c $< $(C_FLAG) $(OPT_FLAG) -I $(HEADER)

libft:
	@make -C libft/

auteur:
	@echo "$(LOGIN_AUTEUR)" > auteur

	#===============================#
#		Cleaning rules			#
#===============================#

clean:
	@/bin/rm -f $(OBJS)
	@echo "*** Object file cleaned ***"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "*** $(NAME) cleaned ***"

re: fclean all

.PHONY: all clean fclean re auteur