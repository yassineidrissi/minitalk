

SRCS = 
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

all :	1337
		gcc server.c -o server