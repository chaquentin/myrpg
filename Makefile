##
## EPITECH PROJECT, 2022
## B-MUL-200-TLS-2-1-myrpg-luca.deltort
## File description:
## Makefile
##


R+BGY = "\e[2;31;103m"
BG%+Y = "\e[22;49;93m"
ALL% = "\e[0m"

TEXT = $(BG%+Y)\\n
TEXT += "         ▄▄▄▄"$(R+BGY)"                   "$(BG%+Y)"▄▄▄▄         \n"
TEXT += "    ▄▄"$(R+BGY)"                                 "$(BG%+Y)"▄▄    \n"
TEXT += "  "$(R+BGY)"        ██████╗ ██████╗  ██████╗         "$(BG%+Y)"  \n"
TEXT += " "$(R+BGY)"         ██╔══██╗██╔══██╗██╔════╝          "$(BG%+Y)" \n"
TEXT += ""$(R+BGY)"          ██████╔╝██████╔╝██║  ███╗          "$(BG%+Y)"\n"
TEXT += ""$(R+BGY)"          ██╔══██╗██╔═══╝ ██║   ██║          "$(BG%+Y)"\n"
TEXT += " "$(R+BGY)"         ██║  ██║██║     ╚██████╔╝         "$(BG%+Y)" \n"
TEXT += "  "$(R+BGY)"        ╚═╝  ╚═╝╚═╝      ╚═════╝         "$(BG%+Y)"  \n"
TEXT += "    ▀▀"$(R+BGY)"                                 "$(BG%+Y)"▀▀    \n"
TEXT += "        ▀▀▀▀"$(R+BGY)"                     "$(BG%+Y)"▀▀▀▀        \n"
TEXT += $(ALL%)

SRC = rpg.c \
	start_game.c
$(eval SRC=$(addprefix src/, $(SRC)))

<<<<<<< HEAD
PLAYER_MANAGEMENT = player_creation.c	\
	display_player.c					\
=======
PLAYER_MANAGEMENT = player_creation.c	 \
	display_player.c 					\
>>>>>>> 9b7d0acbdbd6b4094d5ecc58c2021dd6652f2867
	move_player.c
$(eval PLAYER_MANAGEMENT=$(addprefix src/player_management/, $(PLAYER_MANAGEMENT)))

WEAPON_MANAGEMENT = weapon_creation.c
$(eval WEAPON_MANAGEMENT=$(addprefix src/weapon_management/, $(WEAPON_MANAGEMENT)))

<<<<<<< HEAD
WINDOW_MANAGEMENT = window_creation.c	\
=======
WINDOW_MANAGEMENT = window_creation.c 	\
>>>>>>> 9b7d0acbdbd6b4094d5ecc58c2021dd6652f2867
	create_all_sprites.c
$(eval WINDOW_MANAGEMENT=$(addprefix src/window_management/, $(WINDOW_MANAGEMENT)))

EVENT_MANAGEMENT = manage_key.c 		\
	manage_particles.c
$(eval EVENT_MANAGEMENT=$(addprefix src/manage_event/, $(EVENT_MANAGEMENT)))

CLOTHES_MANAGEMENT = create_clothes.c
$(eval CLOTHES_MANAGEMENT=$(addprefix src/clothes_management/, $(CLOTHES_MANAGEMENT)))

MATHS_MANAGEMENT = is_intersection.c 	\
	get_distance.c
$(eval MATHS_MANAGEMENT=$(addprefix src/maths_management/, $(MATHS_MANAGEMENT)))

ENEMY_MANAGEMENT = enemy_init.c 		\
	display_enemies.c
$(eval ENEMY_MANAGEMENT=$(addprefix src/enemy_management/, $(ENEMY_MANAGEMENT)))

LEVEL_MANAGEMENT = create_map.c 		\
	create_sprite.c 					\
	room_init.c 						\
	display_sprite.c					\
	corners_init.c						\
	corners_count.c
$(eval LEVEL_MANAGEMENT=$(addprefix src/level_management/, $(LEVEL_MANAGEMENT)))

WORD_ARRAY = is_parser.c				\
	my_str_to_word_array.c
$(eval WORD_ARRAY=$(addprefix word_array/, $(WORD_ARRAY)))

STRING_MANAGEMENT = $(WORD_ARRAY) 		\
	my_atoi.c 							\
	my_strlen.c 						\
	my_putnbr.c 						\
	my_strdup.c 						\
	my_strcmp.c
$(eval STRING_MANAGEMENT=$(addprefix src/string_management/, $(STRING_MANAGEMENT)))

VIEW_MANAGEMENT = view_init.c			\
	view_update.c 						\
	view_destroy.c
$(eval VIEW_MANAGEMENT=$(addprefix src/view_management/, $(VIEW_MANAGEMENT)))

DRAWING_FUNCTIONS = draw_line.c			\
	draw_point.c						\
	draw_rays.c
$(eval DRAWING_FUNCTIONS=$(addprefix src/drawing_functions/, $(DRAWING_FUNCTIONS)))


OBJ = 	$(SRC:.c=.o) 					\
		$(CLOTHES_MANAGEMENT:.c=.o)		\
		$(ENEMY_MANAGEMENT:.c=.o)		\
		$(LEVEL_MANAGEMENT:.c=.o)		\
		$(EVENT_MANAGEMENT:.c=.o) 		\
		$(MATHS_MANAGEMENT:.c=.o)		\
		$(PLAYER_MANAGEMENT:.c=.o) 		\
		$(STRING_MANAGEMENT:.c=.o)		\
		$(WEAPON_MANAGEMENT:.c=.o) 		\
		$(WINDOW_MANAGEMENT:.c=.o) 		\
		$(VIEW_MANAGEMENT:.c=.o)		\
		$(DRAWING_FUNCTIONS:.c=.o)		\

%.o: %.c
	@$(CC) -c $< $(CFLAGS) -o $@

NAME = my_rpg

CFLAGS = -I include -Wno-deprecated-declarations
LDFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lm

text:
	@echo $(TEXT)

all: text $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Compilation done"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

rcl: re
	./$(NAME)
	@$(RM) $(OBJ)

debug: CFLAGS += -g3

.PHONY: debug clean fclean re rcl text all
