CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD = ./
LIBFT_HEAD = ./libft/
SRCS = ft_putnbr_base.c ft_printf.c
LIBFT_SRC = ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strlen.c
LIBFT_SRCS = $(addprefix $(LIBFT_HEAD), $(LIBFT_SRC))
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(LIBFT_SRC:.c=.o)
NAME = libftprintf.a
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c -I $(HEAD) -I $(LIBFT_HEAD) $(SRCS) $(LIBFT_SRCS)
	$(AR) $(NAME) $(OBJS) $(LIB_OBJS)
	
fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS) $(LIB_OBJS)

re: fclean all

.PHONY: clean fclean all re
