NAME		=	fatlib.a

BUILD	=	build/

CC			=	gcc

CFLAGS		=	-O3 -Werror

OBJ			=	$(SRC:%.c=%.o)

SRC			=	$(wildcard src/*.c)

INCLUDE		=	-Iinclude

$(NAME)		:	$(OBJ)
		mkdir -p $(BUILD)
		ar rcs $(BUILD)$(NAME) $(OBJ)

$(OBJ)		:	%.o	:	%.c
		$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

all			:	$(NAME)

clean		:
		rm -rf $(OBJ)

fclean		:	clean
		rm -rf $(BUILD)

re		:	fclean all
