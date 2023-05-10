NAME		=	fatlib.a

BUILD	=	build/

CC			=	gcc

CFLAGS		=	-O3 -nostdlib -static

OBJ			=	$(SRC:%.c=%.o)

SRC			=	$(wildcard src/*.c)

INCLUDE		=	-Iinclude

all			:	$(NAME) #$(ASM)

$(NAME)		:	$(OBJ)
		@echo ${NAME}
		@mkdir -p $(BUILD)
		@ar rcs $(BUILD)$(NAME) $(OBJ)

$(OBJ)		:	%.o	:	%.c
		@echo $@
		@$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(ASM)		:	$(ASM_OBJ)
		@$(CC) -c $< -o $@
		@echo $@

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
