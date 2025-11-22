.PHONY: all bonus

NAME := a.out
OBJ := main.o
SRC := main.c
DUMMY := dummy.c
REAL := real.o
BONUS_O := dummy.o

bonus: BONUS_O := real.o
bonus: $(NAME)

all: BONUS_O := dummy.o
all: $(NAME)

$(NAME): $(OBJ) $(BONUS_O)
	clang -Wall -Wextra -Werror $^ -o $@
