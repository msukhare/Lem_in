# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msukhare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 15:46:51 by msukhare          #+#    #+#              #
#    Updated: 2018/05/10 14:56:45 by msukhare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/

SRC_NAME = main.c\
	   read_file.c\
	   error.c\
	   ft_checkrooms.c\
	   manage_lst.c\
	   ft_getinfo.c\
	   ft_check_connect.c\
	   find_paths.c\
	   ft_get_path.c\
	   ft_sort.c\
	   ft_clean_path.c\
	   ft_push_ant.c\
	   ft_push_line_back.c\
	   print_ant_in_rooms.c\
	   ft_checksup_to_int.c\


OBJ_PATH = obj/

CPPFLAGS = -I include/ -I libft/include/

NAME = lem-in

CC = gcc

MK = make -C

SRCLFT = libft/

LFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(LFT) $(NAME)

$(LFT):
	$(MK) $(SRCLFT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(CPPFLAGS) $(OBJ) $(LFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C $(SRCLFT)
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C $(SRCLFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
