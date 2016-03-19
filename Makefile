##
## Makefile for SCROLLER in /home/bougon_p/rendu/gfx_scroller
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Fri Mar 18 20:18:33 2016 bougon_p
## Last update Sun Mar 20 00:04:27 2016 marc brout
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

FIRE		=	src/fire/

WAVE		=	src/wave/

MORT		=	src/mort/

SRC		=	$(MAIN)main.c \
			$(MAIN)background.c \
			$(MAIN)delete.c \
			$(MAIN)init_var.c \
			$(MAIN)display.c \
			$(MAIN)grass.c \
			$(MAIN)check_pos.c \
			$(MAIN)init_sprites.c \
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
