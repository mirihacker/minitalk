SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CFLAGS = -Wall -Wextra -Werror
CC = cc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

PRINTF = printf

all:
	@make -s -C $(PRINTF)
	@cc $(FLAGS) server.c -o $(SERVER)
	@cc $(FLAGS) client.c -o $(CLIENT)
	@echo "Server and Client are Ready!"

bonus:
	@make -s -C $(PRINTF)
	@cc $(FLAGS) server_bonus.c -o $(SERVER_BONUS)
	@cc $(FLAGS) client_bonus.c -o $(CLIENT_BONUS)
	@echo "Server and Client Bonus are Ready!"

clean:
	@make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@rm -f $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY : all bonus clean fclean re