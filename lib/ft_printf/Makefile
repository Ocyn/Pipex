NAME = ft_printf.a

SRCC = ft_printf.c ft_putchar.c ft_putnbr.c \
ft_putstr.c ft_putnbr_base.c ft_put_adress.c


OBJ = $(addprefix $(OBJ_DIR), $(SRCC:.c=.o))

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIB_DIR = ../
OBJ_DIR = OBJ/

all : $(LIB_DIR)$(NAME)

$(OBJ_DIR)%.o : %.c ft_printf.h ../ft_ext.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_DIR)$(NAME) : $(OBJ)
	ar crs $(LIB_DIR)$(NAME) $(addprefix $(OBJ_DIR)/,$(notdir $(OBJ)))

re : fclean $(LIB_DIR)$(NAME)

fclean : clean
	rm -rf $(LIB_DIR)$(NAME)

clean :
	rm -rf $(addprefix $(OBJ_DIR)/,$(notdir $(OBJ)))

.PHONY: all re fclean clean