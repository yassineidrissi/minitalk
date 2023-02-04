SRCS_C = client.c srcs/ft_printf.c srcs/ft_atoi.c
SRCS_S = server.c srcs/ft_printf.c srcs/ft_atoi.c
OBG_C = ${SRCS_C:.c=.o}
OBG_S = ${SRCS_S:.c=.o}
SRCS_BC = client_bonus.c srcs/ft_printf.c srcs/ft_atoi.c
SRCS_BS = server_bonus.c srcs/ft_printf.c srcs/ft_atoi.c
OBG_BC = ${SRCS_BC:.c=.o}
OBG_BS = ${SRCS_BS:.c=.o}
NAME = server client
NAME_B = server_bonus client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : 1337_logo ${NAME_S}

bonus : 1337_logo ${NAME_B}

1337_logo : 
	@echo "\033[92m░░███╗░░██████╗░██████╗░███████╗\033[0m"
	@echo "\033[92m░████║░░╚════██╗╚════██╗╚════██║\033[0m"
	@echo "\033[92m██╔██║░░░█████╔╝░█████╔╝░░░░██╔╝\033[0m"
	@echo "\033[92m╚═╝██║░░░╚═══██╗░╚═══██╗░░░██╔╝░\033[0m"
	@echo "\033[92m███████╗██████╔╝██████╔╝░░██╔╝░░\033[0m"
	@echo "\033[92m╚══════╝╚═════╝░╚═════╝░░░╚═╝░░░\033[0m"
	@echo ""
	@echo "\033[92m generation of client and server exucted files✅\033[0m"


${NAME} : ${OBG}
	${CC} ${CFLAGS} ${OBG_S} -o ${NAME_S}
	${CC} ${CFLAGS} ${OBG_C} -o ${NAME_C}

${NAME_B} : ${OBG_B}
	${CC} ${CFLAGS} ${OBG_BS} -o ${NAME_BS}
	${CC} ${CFLAGS} ${OBG_BC} -o ${NAME_BC}


%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@


clean : 
	@$(RM) ${OBG_S} ${OBG_C}
	@$(RM) ${OBG_BS} ${OBG_BC}
	@echo "\033[31m Delete exucted files🗑\033[31m"

fclean : clean
	@$(RM) ${NAME} ${NAME_B}
	@echo "\033[31m Delete object files🗑\033[31m"

re : fclean all bonus


.PHONY : all clean fclean bonus re 1337_logo