

SRCS = server.c client.c
OBG = ${SRCS:.c=.o}
NAME_S = server
NAME_C = client
CC = gcc
AR = ar -rc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

1337_logo : 
	@echo "\033[92m░░███╗░░██████╗░██████╗░███████╗\033[0m"
	@echo "\033[92m░████║░░╚════██╗╚════██╗╚════██║\033[0m"
	@echo "\033[92m██╔██║░░░█████╔╝░█████╔╝░░░░██╔╝\033[0m"
	@echo "\033[92m╚═╝██║░░░╚═══██╗░╚═══██╗░░░██╔╝░\033[0m"
	@echo "\033[92m███████╗██████╔╝██████╔╝░░██╔╝░░\033[0m"
	@echo "\033[92m╚══════╝╚═════╝░╚═════╝░░░╚═╝░░░\033[0m"
	@echo ""
	@echo "\033[92m generation of client and server exucted files\033[0m"

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME_S} : ${OBG}
	${CC} ${CFLAGS} -o ${NAME_S} server.c

${NAME_C} : ${OBG}
	${CC} ${CFLAGS} -o ${NAME_C} client.c

all :	1337_logo ${NAME_S} ${NAME_C}

clean : 
	$(RM) $(NAME_S) $(NAME_C)

fclean : clean

re : clean all
		