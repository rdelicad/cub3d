NAME	= cub3d
CFLAGS	= -Wall -Werror -Wextra
LIBMLX	= ./MLX42

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a
SRCS	= 	main.c \
			000libft1.c \
			100check.c \
			110initialize.c \
			120errorMessages.c \
			200gnl.c \
			210gnlUtils.c \
			999free.c \
			101checkLimits.c
OBJS	= ${SRCS:.c=.o}
DEBUG	= -fsanitize=address

all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@clear

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@clear

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@clear

re: clean all

.PHONY: all, clean, fclean, re, libmlx, bonus