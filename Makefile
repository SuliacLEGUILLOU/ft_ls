
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
LIBFT=./my_lib/libft.a
SRCS_NAME=	ft_error.c	ft_ls.c	main.c	opt_managment.c \
			sort_file_list.c	s_doc.c	copy_dirent.c \
			get_indir_doc.c	ft_aff_detail.c	set_color.c \
			set_detail.c

SRCS = $(addprefix srcs/,$(SRCS_NAME))
OBJS = $(SRCS:.c=.o)


#===============================#
#		Compilation rules 		#
#===============================#

all: libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT) -I $(HEADER)
	@echo "$(NAME) created and indexed"
	@echo "*** Flag : $(OPT_FLAG) ***"

%.o: %.c
	@$(CC) -o $@ -c $< $(C_FLAG) $(OPT_FLAG) -I $(HEADER)

libft:
	@make -C my_lib/

auteur:
	@echo "$(LOGIN_AUTEUR)" > auteur

#===============================#
#		Cleaning rules			#
#===============================#

clean:
	@/bin/rm -f $(OBJS)
	@echo "*** Object file cleaned ***"

fclean: clean
	@(cd my_lib && $(MAKE) $@)
	@/bin/rm -f $(NAME)
	@echo "*** $(NAME) cleaned ***"

half: clean $(NAME)

re: fclean all

.PHONY: all clean fclean re auteur libft half
