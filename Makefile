CC = gcc
CFLAGS =-O2
IFLAGS = -I./include
NAME = push_swap
LIBFT_DIR = ./libft
LIBFT_AR = $(LIBFT_DIR)/libft.a
SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR),\
        main.c \
        error_handling.c \
		ft_coordinate_compression.c \
		operations.c \
		operations2.c \
		operations3.c \
		push_swap.c\
		dealing2to5.c\
		utils.c)
OBJS =  $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_AR)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT_AR) -o $(NAME)
$(LIBFT_AR):
	$(MAKE) -C $(LIBFT_DIR)
%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -fr $(LIBFT_DIR)/objects

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_AR)
	
re: fclean all
