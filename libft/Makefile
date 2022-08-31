SRCS_B = ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBG_B = ${SRCS_B:.c=.o}
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd_front.c
OBG = ${SRCS:.c=.o}
NAME = libft.a
CC = gcc
AR = ar -rc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf

%.o : %.c
	   ${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBG}
		${AR} $@ ${OBG} 
all: ${NAME}

bonus: ${OBG_B}
	${AR} ${NAME} ${OBG_B}

clean:
		${RM} ${OBG} ${OBG_B}

fclean: clean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus