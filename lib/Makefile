##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME         = libmy.a

SRCS     =  src/mini_printf.c \
	    	src/pourcentage.c \
            src/print_int.c \
            src/print_char.c\
            src/print_string.c \
	    	src/my_compute_power_rec.c \
	    	src/my_compute_square_root.c \
	    	src/my_find_prime_sup.c \
	    	src/my_getnbr.c \
	    	src/my_isneg.c \
	    	src/my_is_prime.c \
	    	src/my_putchar.c \
	    	src/my_put_nbr.c \
	    	src/my_putstr.c \
	    	src/my_revstr.c \
	    	src/my_showstr.c \
	    	src/my_sort_int_array.c \
	    	src/my_strcapitalize.c \
	    	src/my_strcat.c \
	    	src/my_strcmp.c \
	    	src/my_strcpy.c \
	    	src/my_strdup.c \
	    	src/my_str_isalpha.c \
	    	src/my_str_islower.c \
	    	src/my_str_isnum.c \
	    	src/my_str_isprintable.c \
	    	src/my_str_isupper.c \
	    	src/my_strlen.c \
	    	src/my_strlowcase.c \
	    	src/my_strncat.c \
	    	src/my_strncmp.c \
	    	src/my_strncpy.c \
	    	src/my_strstr.c \
	    	src/my_strupcase.c \
	    	src/my_swap.c \
	    	src/my_str_to_word_array.c \
			src/my_int_to_char.c

OBJS     = $(SRCS:.c=.o)

CFLAGS   = -Wall -Wextra -I./include

	GREEN=\033[1;32m
	YELLOW=\033[1;93m
	GREY=\033[2;49m
	ITALIC=\033[3m
	NC=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	 @ ar rc -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(NAME)
	find . -name "#*#" -delete -o -name "*~" -delete
	$(RM) coding-style-reports.log
	clear

fclean: clean
	$(RM) a.out
	clear

re: fclean all

debug: CFLAGS += -g
debug: all

.c.o:
	@ $(CC) -o $(subst .c,.o,$<) -c $< $(CFLAGS) \
		&& echo -e "[ ${GREEN}OK${NC} ] ${GREY}$<${NC}" \
		|| echo -e "[ ${YELLOW}KO${NC} ] ${ITALIC}$<${NC}"

.PHONY: re fclean clean all .c.o
