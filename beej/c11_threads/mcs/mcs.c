#include "mcs.h"

_Atomic (t_wait *) last;

_Atomic (t_queue *) queue;

void	ft_putnbr(int n)
{
	int t = 1;
	char a;
	if (n < 0)
	{
		write(1, "-", 1);
		n = 0 - n;
	}
	while (n / t > 9)
		t *= 10;
	while (t)
	{
		a = ((n / t) % 10) + 48;
		write(1, &a, 1);
		t /= 10;
	}
	write(1, "\n", 1);
}

void	probe(int n, char *a)
{
	int i = 0;
	while (a[i])
		i ++;
	write(1, a, i);
	ft_putnbr(n);
}

void	resize(t_queue *q, int size)
{
//	probe(size, "size: ");
	t_node *new = malloc((size + !size) * sizeof(t_node));
	t_list *l_new = malloc(sizeof(t_list));
	int i = 0;
	t_node *new_dst = atomic_load_explicit(&q->back, memory_order_relaxed);
	t_list *l_new_dst = atomic_load_explicit(&q->l_curr, memory_order_relaxed);
	atomic_store_explicit(&l_new->arr, new, memory_order_relaxed);
	atomic_store_explicit(&new_dst->next, new, memory_order_relaxed);
	atomic_store_explicit(&l_new_dst->next, l_new, memory_order_relaxed);
	atomic_store_explicit(&q->l_curr, l_new, memory_order_relaxed);
	atomic_store_explicit(&q->size, (size * 2) + !size, memory_order_relaxed);
	size --;
	while (i < size)
	{
		atomic_store_explicit(&new[i].next, &new[i + 1], memory_order_relaxed);
		i ++;
	}
	atomic_store_explicit(&new[i].next, 0, memory_order_relaxed);
	atomic_store_explicit(&l_new->next, 0, memory_order_relaxed);
//	size ++;
//	probe(size + size + !size, "new size: ");
}

void	enq(int src)
{
//	write(1, "wah\n", 4);
	t_queue *q = atomic_load_explicit(&queue, memory_order_relaxed);
	int size = atomic_load_explicit(&q->size, memory_order_relaxed);
	int back = atomic_load_explicit(&q->curr_back, memory_order_relaxed);
	if (size < back)
		write(1, "poop\n", 5);
	if (size <= back)
		resize(q, size);
	t_node *curr = atomic_load_explicit(&q->back->next, memory_order_relaxed);
	atomic_store_explicit(&curr->data, src, memory_order_relaxed);
	atomic_store_explicit(&q->back, curr, memory_order_relaxed);
	if (atomic_load_explicit(&q->curr_front, memory_order_relaxed) == 0)
	{
		atomic_store_explicit(&q->curr_front, 1, memory_order_relaxed);
		atomic_store_explicit(&q->front, curr, memory_order_relaxed);
	}
	atomic_store_explicit(&q->curr_back, back + 1, memory_order_relaxed);
}

void	ft_print(t_queue *q)
{
	int n;
	t_node *f = q->front;
	t_node *b = q->back;
	while (f != b)
	{
//		n = atomic_load_explicit(&f->data, memory_order_seq_cst);
		n = f->data;
		ft_putnbr(n);
		f = f->next;
	}
//	n = atomic_load_explicit(&f->data, memory_order_seq_cst);
	n = f->data;
	ft_putnbr(n);
	probe(q->front->data, "Your random number is: ");
}

void	clear_wait(t_wait *head)
{
	t_wait *curr = head;
	t_wait *tmp;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}

void	clear_q(t_queue *q)
{
//	t_list *curr = 0;
//	curr = atomic_load_explicit(&q->list, memory_order_seq_cst);
	t_list *curr = q->list;
	t_list *tmp = 0;
	while (curr)
	{
		free(curr->arr);
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}

int		run(void *a)
{
	int src = *(int *)a;
	t_wait *curr = malloc(sizeof(t_wait));
	atomic_init(&curr->locked, 1);
	atomic_init(&curr->next, 0);
	t_wait *wait = atomic_exchange_explicit(&last, curr, memory_order_acq_rel);
	while (atomic_load_explicit(&wait->locked, memory_order_acquire) == 1)
		__builtin_ia32_pause();//magic wait thing
	enq(src);
	atomic_store_explicit(&wait->next, curr, memory_order_relaxed);
	atomic_store_explicit(&curr->locked, 0, memory_order_release);
	//write(1, "hey\n", 4);
	return (0);
}

int		main(void)
{
	int i = 0;
	int max = 10;
	thrd_t arr[max];
	int src[max];

	t_wait *head = malloc(sizeof(t_wait));
	head->locked = 0;
	head->next = 0;
	t_node *nil = malloc(sizeof(t_node));
	nil->data = 0;
	nil->next = 0;
	t_list *nil2 = malloc(sizeof(t_list));
	nil2->arr = nil;
	nil2->next = 0;
	t_queue dis = {.list = nil2, .arr = nil, .l_curr = nil2, .size = 0, .back = nil, .front = nil, .curr_front = 0, .curr_back = 0};
	//last = &head;
	atomic_store_explicit(&last, head, memory_order_relaxed);
	//queue = &dis;
	atomic_store_explicit(&queue, &dis, memory_order_relaxed);
	while (i < max)
	{
		src[i] = i;
		thrd_create(&arr[i], run, (void *) &src[i]);
		i ++;
	}
	i = 0;
	while (i < max)
		thrd_join(arr[i++], 0);
//	write(1, "yee\n", 4);
	ft_print(&dis);
	clear_q(&dis);
	clear_wait(head);
	/*
	probe(sizeof(_Atomic (struct s_wait *)), "wait size: ");
	probe(sizeof(_Atomic (struct s_node *)), "node size: ");
	probe(sizeof(_Atomic (struct s_list *)), "list size: ");
	*/
}
