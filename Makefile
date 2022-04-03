##
## EPITECH PROJECT, 2022
## B-MUL-200-TLS-2-1-myrpg-luca.deltort
## File description:
## Makefile
##

SRC = rpg.c \
	start_game.c
$(eval SRC=$(addprefix src/, $(SRC)))

PLAYER_MANAGEMENT = player_creation.c \
	display_player.c \
	move_player.c
$(eval PLAYER_MANAGEMENT=$(addprefix src/player_management/, $(PLAYER_MANAGEMENT)))

WEAPON_MANAGEMENT =
$(eval WEAPON_MANAGEMENT=$(addprefix src/weapon_management/, $(WEAPON_MANAGEMENT)))

WINDOW_MANAGEMENT = window_creation.c
$(eval WINDOW_MANAGEMENT=$(addprefix src/window_management/, $(WINDOW_MANAGEMENT)))

EVENT_MANAGEMENT = manage_key.c
$(eval EVENT_MANAGEMENT=$(addprefix src/manage_event/, $(EVENT_MANAGEMENT)))

OBJ = $(SRC:.c=.o) \
	$(PLAYER_MANAGEMENT:.c=.o) \
	$(WEAPON_MANAGEMENT:.c=.o) \
	$(WINDOW_MANAGEMENT:.c=.o) \
	$(EVENT_MANAGEMENT:.c=.o)

NAME = my_rpg

CFLAGS = -I include
LDFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug:	re