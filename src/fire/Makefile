##
## Makefile for scroller in /home/brout_m/RENDU/INFOGRAPHIE/gfx_scroller/src/fire
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Sat Mar 19 22:49:33 2016 marc brout
## Last update Sat Mar 19 22:52:19 2016 marc brout
##

SRCP	= ./

SRC     = $(SRCP)fire.c \
	$(SRCP)aff_fire.c \
	$(SRCP)fire_loop.c

OBJS    = $(SRC:.c=.o)

NAME    = HIGH_WAY_TO_L

CC      = gcc

CFLAGS  = -W -Wall -Werror

LDFLAGS = -L/home/${USER}/.froot/lib \
	-I/home/${USER}/.froot/include \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ -ldl \
	-lm \
	-I../../include/

RM      = rm -f

$(NAME): 
	@$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(CFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
