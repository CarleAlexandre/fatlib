NAME		=	fatlib.a

BUILD	=	build/

CC			=	gcc

CFLAGS		=	-O3

OBJ			=	$(SRC:%.c=%.o)

SRC			=	$(wildcard src/*.c)

INCLUDE		=	-Iinclude

$(NAME)		:	$(OBJ)
		@echo ${NAME}
		@mkdir -p $(BUILD)
		@ar rcs $(BUILD)$(NAME) $(OBJ)

$(OBJ)		:	%.o	:	%.c
		@echo $@
		@$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

all			:	$(NAME)

test		:
		@echo "test"

clean		:
		@echo "clean : $$?"
		@rm -rf $(OBJ)

fclean		:	clean
		@rm -rf $(BUILD)
		@echo "full clean : $$?"

re		:	fclean all
		@echo "make re $$?"

.PHONY	:	re clean fclean test
