NAME = push_swap
NAME_BONUS = checker

CFLAGS= -Wall -Wextra -Werror 
SRCS =	mandatory/ss.c \
		mandatory/push_a.c\
		mandatory/push_b.c \
		mandatory/rotate.c \
		mandatory/check_stack.c\
		mandatory/main.c\
		mandatory/sort.c \
		mandatory/min_value.c \
		mandatory/max_value.c \
		mandatory/reverse_rotate.c \
		mandatory/bigsort.c \

SRC_BONUS =	bonus/main.c \
			bonus/stack_a.c \
			bonus/stack_b.c \
			bonus/stack.c \
			bonus/utils.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c \
			bonus/check_stack_bonus.c \

LIB=./libft/libft.a

OBJ = ${SRCS:.c=.o}
OBJB = ${SRC_BONUS:.c=.o}
all : ${NAME}
bonus :	${NAME_BONUS}

${NAME} : $(LIB) ${OBJ}
	cc    -o $(NAME) $(OBJ) $(LIB)
	
${NAME_BONUS} : ${LIB} ${OBJB}
	cc    -o $(NAME_BONUS) $(OBJB) $(LIB)

$(LIB):
	cd libft && make
clean :
	rm -f ${OBJ} ${OBJB}
	cd ./libft && make clean

fclean : clean
	rm -f ${NAME} ${NAME_BONUS}
	cd libft && make fclean
re : fclean all
.SILENT:
