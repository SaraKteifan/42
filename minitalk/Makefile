CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC_PATH    = src/
OBJ_PATH    = build/
INCLUDE     = include/
LIBFT_PATH  = lib/libft/

LIBFT       = $(LIBFT_PATH)libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

SERVER  = server
CLIENT  = client

SRC_FILES   = $(SERVER) $(CLIENT)
SRC         = $(addprefix $(SRC_PATH), $(addsuffix .c, $(SRC_FILES)))
OBJ         = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(SRC_FILES)))

all: $(LIBFT) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_PATH)server.o $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $< $(LIBFT_FLAGS)

$(CLIENT): $(OBJ_PATH)client.o $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $< $(LIBFT_FLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | build
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

build:
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
