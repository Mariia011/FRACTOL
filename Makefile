NAME = fractol
BONUS = b_fractol
GCC = cc
MLXFLAGS = -Lmlx -lmlx -framework OpenGl -framework Appkit -lm

HELPERPATH = ./libft/
HELPER = $(HELPERPATH)libft.a
MAKE = make -C

MANDATORY = $(wildcard ./*.c)

OBJS = $(patsubst %.c, %.o, $(MANDATORY))

all : $(NAME)

$(NAME) : $(OBJS) $(HELPER)
	$(GCC) ./main/fractol.c $(MLXFLAGS) $(OBJS) $(HELPER) -o $@

$(HELPER) :
	$(MAKE) $(HELPERPATH)

%.o : %.c Makefile
	$(GCC) -c $< -o $@

bonus: $(BONUS)

$(BONUS) : $(OBJS) $(HELPER)
	$(GCC) ./main/fractol_bonus.c  $(MLXFLAGS) $(OBJS) $(HELPER) -o $@

clean :
	$(MAKE) $(HELPERPATH) clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) $(HELPERPATH) fclean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY : all clean fclean re
