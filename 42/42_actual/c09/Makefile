CC := clang

CC_FLAGS := -Wall -Wextra -Werror -c

AR := ar

AR_FLAGS := rcs

dot_o := o1.o o2.o o3.o o4.o o5.o

all: libft.a

libft.a: $(dot_o)
	$(AR) $(AR_FLAGS) $@ $^

o1.o: ft_putchar.c
	$(CC) $(CC_FLAGS) $< -o $@
o2.o: ft_swap.c
	$(CC) $(CC_FLAGS) $< -o $@
o3.o: ft_putstr.c
	$(CC) $(CC_FLAGS) $< -o $@
o4.o: ft_strlen.c
	$(CC) $(CC_FLAGS) $< -o $@
o5.o: ft_strcmp.c
	$(CC) $(CC_FLAGS) $< -o $@

clean:
	rm -f $(dot_o)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re
