NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = src/ft_printf.c \
	   src/ft_error_print.c \
	   src/ft_print_cs.c \
	   src/ft_store_specs_info.c \
	   src/ft_utils_print.c \
	   src/ft_print_p.c \
	   src/ft_print_per.c \
	   src/ft_print_di.c \
	   src/ft_print_ux.c \
	   src/ft_ux_fuc.c \

OBJCS = $(SRCS:%.c=%.o)

INCLUDE = ./includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -I$(LIBFT_DIR)

ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJCS)
		$(MAKE) -C $(LIBFT_DIR) bonus
		cp $(LIBFT_LIB) $(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJCS)

clean: 
		$(MAKE) -C $(LIBFT_DIR) clean
		$(RM) $(OBJCS)

fclean: 
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(OBJCS)
		$(RM) $(NAME)

re: fclean all

test: 
		gcc -I includes -I libft  -g main.c ./src/*.c ./libft/*.c 


.PHONY: all clean fclean re test
