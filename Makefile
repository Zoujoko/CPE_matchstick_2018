##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

SRC_DIR	=	src/
LIB_DIR	=	lib/my/
INC_DIR	=	include/
TESTS_DIR	=	tests/

NAME	=	matchstick

CFLAGS	=	-g -Wall -Wextra -I $(INC_DIR)

LDFLAGS	=	-L $(LIB_DIR) -lmy

SRC	=	$(SRC_DIR)make_map.c \
		$(SRC_DIR)update_map.c \
		$(SRC_DIR)matchstick.c \
		$(SRC_DIR)ai.c \
		$(SRC_DIR)error.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(NAME)

# `make` normal
$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

# `make clean` clean lib/*.o + projet
clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

# `make clean` clean + binary/library
fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
