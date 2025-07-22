MAIN = main.c
SRC = src/strbuffer.c src/table.c
HEADER = SRC:.c=.h
FLAG = -Wall -g
NAME = CDATA

$(NAME): $(SRC)
	gcc $(FLAG) $^ $(MAIN) -o $@



