NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	srcs/ft_printf.c \
		srcs/ft_utils.c \
		srcs/ft_convert/ft_convert_c.c \
		srcs/ft_convert/ft_convert_d.c \
		srcs/ft_convert/ft_convert_i.c \
		srcs/ft_convert/ft_convert_p.c \
		srcs/ft_convert/ft_convert_s.c \
		srcs/ft_convert/ft_convert_u.c \
		srcs/ft_convert/ft_convert_x.c \
		srcs/ft_convert/ft_convert_xx.c
OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	ar cr $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re