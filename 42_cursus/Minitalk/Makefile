SERVER = server

CLIENT = client

HEADER = minitalk.h


CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER) $(HEADER)

$(SERVER): server.c $(HEADER)
	@gcc server.c extra.c -o $@
	@echo $@ ----------------- ready -----------------

$(CLIENT): client.c $(HEADER)
	@gcc $(CFLAGS) client.c extra.c -o $@
	@echo $@ ----------------- ready -----------------

clean:
	rm -rf $(SERVER) $(CLIENT)

fclean: clean
	rm -rf $(SERVER) $(CLIENT) Minitalk.a

re: fclean all

.PHONY: all re clean fclean