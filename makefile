SRCS_C = client.c srcs/ft_printf.c srcs/ft_atoi.c
SRCS_S = server.c srcs/ft_printf.c srcs/ft_atoi.c
OBG_C = ${SRCS_C:.c=.o}
OBG_S = ${SRCS_S:.c=.o}
SRCS_BC = client_bonus.c srcs/ft_printf.c srcs/ft_atoi.c
SRCS_BS = server_bonus.c srcs/ft_printf.c srcs/ft_atoi.c
OBG_BC = ${SRCS_BC:.c=.o}
OBG_BS = ${SRCS_BS:.c=.o}
NAME_S = server
NAME_C = client
NAME_BS = server_bonus
NAME_BC = client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : 1337_logo ${NAME_S} ${NAME_C}

bonus : 1337_logo ${NAME_BS} ${NAME_BC}

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

${NAME_BS} : ${OBG_BS}
	@${CC} ${CFLAGS} ${OBG_BS} -o ${NAME_BS}

${NAME_BC} : ${OBG_BC}
	@${CC} ${CFLAGS} ${OBG_BC} -o ${NAME_BC}


%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@


clean : 
	@$(RM) ${OBG_S} ${OBG_C}
	@$(RM) ${OBG_BS} ${OBG_BC}
	@echo "\033[31m Delete exucted files🗑\033[31m"

fclean : clean
	@$(RM) ${NAME_S} ${NAME_C}
	@$(RM) ${OBG_BS} ${OBG_BC}
	@echo "\033[31m Delete object files🗑\033[31m"

re : fclean all bonus


.PHONY : all clean fclean bonus re 1337_logo