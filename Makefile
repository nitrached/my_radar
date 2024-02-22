##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME         = my_radar

SRCS     =  src/main.c \
			src/get_info/get_info.c \
			src/get_info/add_aircraft.c \
			src/get_info/add_tower.c \
			src/simulation/play_simulation.c \
			src/create_tool_simulation/create_window.c \
			src/simulation/handle_events/handle_event.c \
			src/simulation/draw_entity.c \
			src/simulation/move_entity.c \
			src/simulation/get_direction.c \
			src/simulation/rotate_sprite.c \
			src/simulation/destroy/delete_aircraft.c \
			src/simulation/destroy/delete_colision.c \
			src/simulation/destroy/delete_arrival.c \
			src/simulation/draw_hitbox.c \
			src/simulation/is_active.c \
			src/simulation/timer.c \
			src/simulation/print_multiply.c \
			src/simulation/dash_h.c \
			src/simulation/innit.c


OBJS     = $(SRCS:.c=.o)

CFLAGS   = -Wall -Wextra -I include -I lib/include

	GREEN=\033[1;32m
	YELLOW=\033[1;93m
	GREY=\033[2;49m
	ITALIC=\033[3m
	NC=\033[0m

all: $(NAME)

$(NAME): build_lib $(OBJS)
	@ gcc -o $(NAME) $(OBJS) -L./lib -lmy -lcsfml-system -lcsfml-window \
	  -lcsfml-graphics -lcsfml-audio -lm
build_lib:
	make -C ./lib

clean:
	$(RM) $(OBJS) $(NAME)
	find . -name "#*#" -delete -o -name "*~" -delete
	$(RM) coding-style-reports.log
	$(RM) vgcore*
	clear

fclean: clean
	make fclean -C ./lib
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
