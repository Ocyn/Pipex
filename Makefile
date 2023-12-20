NAME = pipex

SRCC_DIR = src/

SRCC = \
pipex.c \
ft_parsing.c \
ft_error_closing.c \
ft_tools.c \
ft_shell_path.c \
ft_command_1.c \
ft_command_2.c

SRCC_PATH = $(addprefix $(SRCC_DIR),$(SRCC))

CC = cc
FLAGS = -Wall -Wextra -Werror -g3

INCLUDE = -I .
HEADER = pipex.h
HEADER_PATH =  $(SRCC_DIR)$(HEADER)

OBJ_DIR = OBJ/
OBJ_PATH = $(SRCC_DIR)$(OBJ_DIR)

LIB_DIR = lib/
LIB_LIBFT_DIR = $(LIB_DIR)Libft/
LIB_PRINTF_DIR = $(LIB_DIR)ft_printf/
LIB = 	libft.a \
		ft_printf.a

LIB1 = $(LIB_DIR)/libft.a
LIB2 = $(LIB_DIR)/ft_printf.a

LIB_PATH = $(addprefix $(LIB_DIR), $(LIB))

OBJ = $(addprefix $(OBJ_PATH), $(SRCC:.c=.o))

all : $(NAME) 

$(LIB1): force
	@make -sC $(LIB_DIR)Libft/

$(LIB2): force
	@make -sC $(LIB_DIR)ft_printf/

$(NAME): $(OBJ) $(LIB1) $(LIB2)
	$(CC) $(FLAGS) $(OBJ) $(INCLUDE) $(LIB_PATH) -o $(NAME)

$(OBJ_PATH)%.o : $(SRCC_DIR)%.c $(HEADER_PATH)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

re : fclean $(NAME)

fclean : clean
	rm -rf $(NAME)
	rm -rf lib/*.a
	make fclean -C $(LIB_DIR)Libft/
	make fclean -C $(LIB_DIR)ft_printf/

clean :
	rm -rf $(OBJ)
	make clean -C $(LIB_DIR)Libft/
	make clean -C $(LIB_DIR)ft_printf/

force :

.PHONY: all re fclean clean force