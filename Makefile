NAME = fractol

GCC = cc
MLXFLAGS = -Lmlx -lmlx -framework OpenGl -framework Appkit -lm

HELPERPATH = ./libft/
HELPER = $(HELPERPATH)libft.a
DEBUG = -fsanitize=address
MAKE = make -C

MANDATORY = $(wildcard ./*.c)

OBJS = $(patsubst %.c, %.o, $(MANDATORY))

all : $(NAME)

$(NAME) : $(OBJS) $(HELPER)
	$(GCC) $(DEBUG) $(MLXFLAGS) $(OBJS) $(HELPER) -o $@

$(HELPER) :
	$(MAKE) $(HELPERPATH)

%.o : %.c Makefile
	$(GCC) -c $< -o $@

clean :
	$(MAKE) $(HELPERPATH) clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) $(HELPERPATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
