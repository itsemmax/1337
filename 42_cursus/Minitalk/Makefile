SERVER = server

SRV_BNS = server_bonus

CLIENT = client

CLT_BNS = client_bonus

CFLAGS = -Wall -Wextra -Werror

YELLOW = \033[0;33m

RED = \033[0;31m

GREEN = \033[0;32m

all: $(CLIENT) $(SERVER)

	@echo "$(GREEN) ------------enjoy----------"

$(SERVER): server.c extra.c
	@gcc $(CFLAGS) server.c extra.c -o $@
	@echo "$(YELLOW)$@----------------- ready -----------------"

$(CLIENT): client.c extra.c
	@gcc $(CFLAGS) client.c extra.c -o $@
	@echo "$(YELLOW)$@ ----------------- ready -----------------"

bonus: $(SRV_BNS) $(CLT_BNS)

	@echo "$(GREEN) ------------enjoy----------"

$(CLT_BNS): client_bonus.c extra_bonus.c
	@gcc $(CFLAGS) client_bonus.c extra_bonus.c -o $@
	@echo "$(RED)$@ ----------------- ready -----------------"

$(SRV_BNS): server_bonus.c extra_bonus.c
	@gcc $(CFLAGS) server_bonus.c extra_bonus.c -o $@
	@echo "$(RED)$@ ----------------- ready -----------------"

clean:
	rm -rf $(SERVER) $(CLIENT) $(SRV_BNS) $(CLT_BNS)

fclean: clean
	rm -rf  Minitalk.a

re: fclean all bonus

.PHONY: all re clean fclean bonus