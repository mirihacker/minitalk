NAME = libftprintf.a
SRCS = ft_digit.c ft_printf.c
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re