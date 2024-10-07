NAME = pushswap
NAME_BONUS = checker

REM		=	rm -rf

SRCS =	\
    operations/rev_rotate.c \
    operations/push.c \
    operations/rotate.c \
    operations/swap.c \
    utils/ft_is_sorted.c \
    utils/ft_lstsize.c \
    utils/handle_errors.c \
    utils/ft_add_back.c \
    utils/ft_lstlast.c \
    utils/ft_split.c \
    utils/parse_input.c \
    pushswap.c \


OBJS = $(SRCS:.c=.o)

# CFLAGS = -Wall -Wextra -Werror


all: $(NAME)


$(NAME): $(OBJS)
	cc $(CFLAGS) $^ -o $@

%.o:%.c
	cc -c $(CFLAGS) $< -o $@

clean: 
	$(REM) $(OBJS)

fclean: 
	$(REM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re