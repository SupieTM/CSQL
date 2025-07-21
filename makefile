MAIN = main.c
SRC = src/strbuffer.c
HEADER = SRC:.c=.h
FLAG = -Wall
NAME = CDATA

$(NAME): $(SRC)
	gcc $(FLAG) $^ $(MAIN) -o $@



