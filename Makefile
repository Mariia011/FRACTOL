NAME = fractol

GCC = cc *.c
MLXFLAGS = -Lmlx -lmlx -framework OpenGl -framework Appkit -lm

HELPERPATH = ./libft/
# MINILIBX = /Users/marikhac/Desktop/fractol/MiniLibX
HELPER = $(HELPERPATH)libft.a
# DEBUG = -fsanitize=address
MAKE = make -C

MANDATORY = ./*.c

OBJS = $(MANDATORY:.c=.o)

all : $(NAME)

$(NAME) : $(HELPER) $(OBJS)
	$(GCC) $(MLXFLAGS) $(OBJS) $(HELPER) -o $@

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
