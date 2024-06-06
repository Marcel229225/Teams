##
## EPITECH PROJECT, 2020
## myteams
## File description:
## makefile
##

SRC	=	./server/error.c \
		./server/my_teams.c \
		./server/other_cmd.c \
		./server/separation.c \
		./client/my_split.c \
		./server/format.c

SRC1	=	./client/client2.c \
		./client/client.c \
		./client/clientmain.c \
		./client/cmd.c \
		./client/util.c \
		./client/my_split.c

OBJ		=	$(SRC:.c=.o)

OBJ1	=	$(SRC1:.c=.o)

CC 		= gcc

NAME	=	myteams_server

NAME1	=	myteams_cli

all:		$(NAME) $(NAME1)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) -luuid -L./libs/myteams -lmyteams -g3

$(NAME1):	$(OBJ1)
	$(CC) -o $(NAME1) $(SRC1) -luuid -L./libs/myteams -lmyteams -g3

clean:
	rm -f $(OBJ) $(OBJ1)
	rm -f stock
	rm -f *~

fclean: clean
	rm -f $(NAME) $(NAME1)
	rm -f *~

re: clean all

.PHONY: all clean fclean re
