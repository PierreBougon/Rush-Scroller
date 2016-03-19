##
## Makefile for SCROLLER in /home/bougon_p/rendu/gfx_scroller
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Fri Mar 18 20:18:33 2016 bougon_p
## Last update Sat Mar 19 17:08:49 2016 benjamin duhieu
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e


# SOURCES VARIABLES

MAIN		=	./

SRC		=	$(MAIN)sampler.c \
			$(MAIN)main.c \

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

NAME	=	demo

IFLAG	=	-I../include/

CFLAGS  =	-W -Wall -Wextra $(IFLAG)

CC      =	gcc -g $(CFLAGS)



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
