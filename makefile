

SRCS_C = client.c srcs/ft_printf.c srcs/ft_atoi.c
SRCS_S = server.c srcs/ft_printf.c srcs/ft_atoi.c
OBG_C = ${SRCS_C:.c=.o}
OBG_S = ${SRCS_S:.c=.o}
NAME_S = server
NAME_C = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : 1337_logo ${NAME_S} ${NAME_C}

1337_logo : 
	@echo "\033[92m░░███╗░░██████╗░██████╗░███████╗\033[0m"
	@echo "\033[92m░████║░░╚════██╗╚════██╗╚════██║\033[0m"
	@echo "\033[92m██╔██║░░░█████╔╝░█████╔╝░░░░██╔╝\033[0m"
	@echo "\033[92m╚═╝██║░░░╚═══██╗░╚═══██╗░░░██╔╝░\033[0m"
	@echo "\033[92m███████╗██████╔╝██████╔╝░░██╔╝░░\033[0m"
	@echo "\033[92m╚══════╝╚═════╝░╚═════╝░░░╚═╝░░░\033[0m"
	@echo ""
	@echo "\033[92m generation of client and server exucted files✅\033[0m"


${NAME_S} : ${OBG_S}
	@${CC} ${CFLAGS} ${OBG_S} -o ${NAME_S}

${NAME_C} : ${OBG_C}
	@${CC} ${CFLAGS} ${OBG_C} -o ${NAME_C} 

%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean : 
	@$(RM) ${OBG_S} ${OBG_C}
	@echo "\033[31m Delete exucted files🗑\033[31m"

fclean : clean
	@$(RM) ${NAME_S} ${NAME_C}
	@echo "\033[31m Delete object files🗑\033[31m"
re : fclean all

.PHONY : all clean fclean re 1337_logo