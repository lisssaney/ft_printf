NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = structure/ft_changer.c \
		structure/ft_printf.c \
		structure/ft_setupper.c \
		includes/ft_extra_incl.c \
		includes/ft_includes.c \
		types/ft_numbers.c \
		types/ft_signs.c

all: $(NAME)

$(NAME):
		gcc -c $(FLAGS) $(SRCS)
		ar rc $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all