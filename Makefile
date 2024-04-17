NAME = fractol

GCC = cc
MLXFLAGS = -Lmlx -lmlx -framework OpenGl -framework Appkit

HELPERPATH = ./libft/
# MINILIBX = /Users/marikhac/Desktop/fractol/MiniLibX
HELPER = $(HELPERPATH)libft.a
DEBUG = -fsanitize=address
MAKE = make -C

MANDATORY = ./*.c

OBJS = $(MANDATORY:.c=.o)

all : $(NAME)

$(NAME) : $(HELPER) $(OBJS)
	$(GCC) $(DEBUG) $(MLXFLAGS) $(OBJS) $(HELPER) -o $@

$(HELPER) :
	$(MAKE) $(HELPERPATH)

%.o : %.c
	$(GCC) -c $^

clean :
	$(MAKE)  $(HELPERPATH) clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE)  $(HELPERPATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
