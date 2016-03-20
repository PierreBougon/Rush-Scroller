##
## Makefile for SCROLLER in /home/bougon_p/rendu/gfx_scroller
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Fri Mar 18 20:18:33 2016 bougon_p
## Last update Sun Mar 20 09:28:53 2016 benjamin duhieu
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e


# SOURCES VARIABLES

MAIN		=	src/

PLAYER		=	src/player/

SAMPLER		=	src/sampler/

GAME		=	src/game/

FIRE		=	src/fire/

WAVE		=	src/wave/

MORT		=	src/mort/

SRC		=	$(MAIN)main.c \
			$(GAME)init_var.c \
			$(GAME)display.c \
			$(GAME)background.c \
			$(GAME)delete.c \
			$(GAME)grass.c \
			$(GAME)check_pos.c \
			$(GAME)init_sprites.c \
			$(PLAYER)player.c \
			$(PLAYER)player_moves.c \
			$(SAMPLER)sampler.c \
			$(SAMPLER)init_sampler.c \
			$(SAMPLER)load_double_tab.c \
			$(FIRE)aff_fire.c \
			$(FIRE)fire.c \
			$(FIRE)fire_loop.c \
			$(WAVE)rohan.c \
			$(WAVE)new.c \
			$(MORT)mort.c \
			$(MORT)new_mort.c

OBJS    	=	$(SRC:.c=.o)

# LIBRARY VARIABLES                                                

LIB     =       -L/home/${USER}/.froot/lib/ -llapin \
                -lsfml-audio \
		-lsfml-graphics \
                -lsfml-window \
		-lsfml-system \
                -lstdc++ -ldl \
		-lm

FLAG    =       -I/home/${USER}/.froot\

# PROJECT VARIABLES

NAME	=	MegaDemo

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra -g $(IFLAG)

CC      =	gcc $(CFLAGS) -D LAPIN_ALLOCATOR_DEACTIVATED



# PROJECT RULES

$(NAME)		: 	$(OBJS)
			@$(ECHO) "$(GREEN)\n> Compiling project\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LIB)

all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
