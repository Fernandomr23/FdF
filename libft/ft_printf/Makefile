NAME = libftprintf.a

SOURCE = \
		 ft_printf.c ft_putchar.c ft_putstr.c ft_paramtype.c ft_putpercentage.c \
		 ft_putnbr.c ft_putuint.c ft_puthex.c ft_putptr.c

CC = gcc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

OBJS = ${SOURCE:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#comp:
#	$(CC) $(CFLAGS) $(NAME) main.c
