NAME		=	fatlib.a

BUILD		=	build/

CC			=	gcc

CFLAGS		=	-O3 -nostdlib -static

OBJ			=	$(SRC:%.c=%.o)

ASM_OBJ		=	$(ASM_SRC:%.asm=%.o)

SRC			=	$(wildcard src/*.c)

ASM_SRC		=	$(wildcard asm/*.asm)

INCLUDE		=	-Iinclude -I singleHeader

all			:	$(NAME) $(ASM_OBJ)

$(NAME)		:	$(OBJ)
		@mkdir -p $(BUILD)
		@ar rcs $(BUILD)$(NAME) $(OBJ)
		@echo ${NAME}

$(OBJ)		:	%.o	:	%.c
		@$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@
		@echo $@

$(ASM_OBJ)		:	%.o	:	%.asm
		@nasm $< -o $@
		@echo $@

clean		:
		@rm -rf $(OBJ)
		@rm -rf $(ASM_OBJ)
		@echo "clean : $$?"

fclean		:	clean
		@rm -rf $(BUILD)
		@echo "full clean : $$?"

re		:	fclean all
		@echo "make re ..."

.PHONY	:	re clean fclean test
