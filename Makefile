# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaefer <rafaefer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 14:39:45 by rafaefer          #+#    #+#              #
#    Updated: 2024/11/28 11:03:37 by rafaefer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

FLAGS = -Wall -Wextra -Werror -g -Iheaders/
CC = cc

LIBFT = libft/libft.a
LIBFTMK = libft
LIBFT_REPO = https://github.com/RafaelSKD/Libft_Ultra.git

all: libft
	@$(CC) $(FLAGS) server.c -o $(SERVER) $(LIBFT)
	@$(CC) $(FLAGS) client.c -o $(CLIENT) $(LIBFT)
	@echo "Server And Client Are Ready!"

libft:
	@if [ ! -d "$(LIBFTMK)" ]; then \
		echo "Cloning libft from $(LIBFT_REPO)..."; \
		git clone $(LIBFT_REPO) $(LIBFTMK); \
	fi
	@$(MAKE) -C $(LIBFTMK)

clean:
	@$(MAKE) clean -s -C $(LIBFTMK)

fclean: clean
	@$(MAKE) fclean -s -C $(LIBFTMK)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all
