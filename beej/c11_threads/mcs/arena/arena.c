//atomic semantics? throw atomic_init at the problem
//if this struct isnt 16 bytes I am cooked
//

#include "arena.h"

int kb = 4096;
int chunk = kb / sizeof(t_generic);//256

t_book pool = {.size = 0, .front = 0, .head = 0, .tail = 0};
t_book book = {.size = 0, .front = 0, .head = 0, .tail = 0};

#include <unistd.h>

t_generic	*arena_gib(int count)
{
	int i = 0;
	int k = (chunk * count) - 1;
	t_generic *curr = 0;

	if (count < 1)
		return (0);
	curr = (t_generic *) mmap(0, kb * count, PROT_READ | PROT_WRITE , MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (curr == MAP_FAILED)
	{
		write(1, "stinky\n", 7);
		return (0);
	}
	while (i < k)
	{
		curr[i].next = &curr[i + 1];
		i ++;
	}
	curr[i].next = 0;
	return (curr);
}

t_generic	*me_alloc(int num)
{
	int i = 1;
	int real = (num / chunk) + (num + pool.front > chunk);

	t_generic *curr;

	if (num < 1)
		return (0);
	if (pool.size <= pool.front + num)
	{
		pool.size += chunk * real;
		book.front += 1;
		if (book.size - book.front < 1)//init or update book keeping
		{
			book.size += chunk;
			curr = arena_gib(1);
			if (!book.head)
				book.head = curr;
			else
				book.tail->next = curr;
		}
		if (!book.tail)//init or update
			book.tail = book.head;
		else
			book.tail = book.tail->next;

		curr = arena_gib(real);
		book.tail->self = curr;
		if (!pool.head)
		{
			pool.head = curr;
			pool.tail = curr[(chunk * real) - 1];
		}
		else
			pool.tail = pool.tail->next[(chunk * real) - 1];
	}
	pool.front += num;
	curr = pool.head;
	while (i < num)
	{
		i ++;
		curr = curr->next;
	}
	t_generic *tmp = curr->next;
	curr->next = 0;
	curr = pool.head;
	pool.head = tmp;
	return (curr);
}
