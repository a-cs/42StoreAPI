# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 20:25:23 by acarneir          #+#    #+#              #
#    Updated: 2022/02/27 16:36:36 by acarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42store_api
CLI = 42store_cli

CC = gcc

FLAGS = -Wall -Wextra -Werror
MYSQL_FLAGS = `mysql_config --cflags --libs`


API_INCLUDE_DIR = ./api/includes
API_INCLUDE = -I $(API_INCLUDE_DIR)

LIBS_DIR = ./api//libs
LIBS = $(LIBS_DIR)/*.c

LIBFT_DIR = ./api/libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

API_SRC_DIR = ./api/src
API_SRCS = main.c \
		routes/routes.c \
		routes/items_routes.c \
		routes/transactions_routes.c \
		routes/root_route.c \
		services/list_items_service.c \
		services/create_item_service.c \
		services/list_transactions_service.c \
		services/create_transaction_service.c \
		utils.c

API_OBJ_DIR = ./api/objs
API_OBJS := $(addprefix $(API_OBJ_DIR)/,$(API_SRCS:.c=.o))
API_SRCS := $(addprefix $(API_SRC_DIR)/,$(API_SRCS))

CLI_INCLUDE_DIR = ./cli/includes
CLI_INCLUDE = -I $(CLI_INCLUDE_DIR)

CLI_SRC_DIR = ./cli/src
CLI_SRCS = main.c \
		functions.c

CLI_OBJ_DIR = ./cli/objs
CLI_OBJS := $(addprefix $(CLI_OBJ_DIR)/,$(CLI_SRCS:.c=.o))
CLI_SRCS := $(addprefix $(CLI_SRC_DIR)/,$(CLI_SRCS))


all: $(NAME) $(CLI)

$(NAME): $(LIBFT)  $(API_OBJS)
	$(CC) -o $(NAME) $(API_OBJS) $(LIBFT) $(LIBS) $(MYSQL_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(API_OBJ_DIR)/%.o: $(API_SRC_DIR)/%.c
	mkdir -p $(API_OBJ_DIR)/routes
	mkdir -p $(API_OBJ_DIR)/services
	$(CC) $(FLAGS) $(API_INCLUDE) -c $< -o $@

$(CLI): $(LIBFT)  $(CLI_OBJS)
	$(CC) -o $(CLI) $(CLI_OBJS) $(LIBFT) $(MYSQL_FLAGS)

$(CLI_OBJ_DIR)/%.o: $(CLI_SRC_DIR)/%.c
	mkdir -p $(CLI_OBJ_DIR)
	$(CC) $(FLAGS) $(CLI_INCLUDE) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(API_OBJ_DIR)
	rm -rf $(CLI_OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
	rm -rf $(CLI)

re : fclean all