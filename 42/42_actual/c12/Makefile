CC := clang
CC_FLAGS := -Wall -Wextra -Werror
AR := ar
AR_FLAGS := rcs
C_FILES := $(wildcard *.c)
O_FILES := $(C_FILES:.c=.o)

all: lib_list.a
#	$(CC) $(CC_FLAGS) $^

lib_list.a: obj
	$(AR) $(AR_FLAGS) $@ $(O_FILES)

obj: $(C_FILES)
	$(CC) $(CC_FILES) -c $(C_FILES)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f lib_list.a

re: fclean all

.PHONY: all clean fclean re
