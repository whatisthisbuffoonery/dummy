#include "postfix.h"

void	ft_putstr(char *a)
{
	int i = 0;
	while (a[i])
		i ++;
	write(1, a, i);
}

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
}

void	probe(int n, char *a)
{
	int i = 0;
	while (a[i])
		i ++;
	write(1, a, i);
	ft_putnbr(n);
	write(1, "\n", 1);
}

void	ft_set(char *a, int n)
{
	int i = 0;
	while (i < n)
		a[i++] = 0;
	a[i] = 0;
}

void	ft_atoa(t_op *op, char *src, int *index)
{
	int i = *index;
	int k = 0;
	int j = 0;
	if (src[i] == '-')
		j ++;
	while (src[i] && src[i] != ' ')
		i ++;
	k = i - *index;
	op->num = malloc((k + 1) * sizeof(char));
	i = *index;
	k = 0;
	while (src[i + k] && src[i + k] != ' ')
	{
		op->num[k] = src[i + k];
		k ++;
	}
	op->num[k] = 0;
	if (op->num[j] > '9')
		op->type = alg;
	*index += k;
}

t_op	*make(t_op *n)
{
	t_op *a = malloc(sizeof(t_op));
	if (!n)
		n = a;
	a->next = n;
	a->type = nil;
	a->num = 0;
	a->data = 0;
	return (a);
}

t_wait	enq(t_queue *q, char *src, int *index)
{
	int i = *index;
	char c = src[i];
	t_op *back = q->back;
	back->next = make(q->nil);
	back = back->next;
	q->size += 1;
	switch (c)
	{
		case '-':
			if (src[i + 1] != ' ')
				back->type = num;
			else
				back->type = as;
			break;
		case '+':
			back->type = as;
			break;
		case '*':
		case '/':
		case '%':
			back->type = md;
			break;
		case '^':
			back->type = e;
			break;
		case '(':
		case ')':
			back->type = p;
			break;
		default:
			back->type = num;
	}
	if (q->front->type == nil)
		q->front = back;
	q->back = back;
	if (back->type == num)
	{
		ft_atoa(back, src, index);
		return (w_num);
	}
	back->data = c;
	if (c == '(')
		return (w_num);
	return (op);
//	probe(back->type, "back: ");
}

t_queue *create_q(void)
{
	t_queue *q = malloc(sizeof(t_queue));
	q->nil = make(0);
	q->back = q->nil;
	q->front = q->nil;
	q->size = 0;
	return (q);
}

void	throw(t_wait wait, char b, char *str)
{
	write(1, "expecting ", 10);
	if (wait == w_num)
		write(1, "operand, ", 9);
	else
		write(1, "operator, ", 10);
	write(1, "got: ", 5);
	if (wait == w_num)
		write(1, &b, 1);
	else
		ft_putstr(str);
	write(1, "\n", 1);
}

t_queue	*ft_me_dup(char *src)
{
	int a = -1;
	int size = 0;
	char b;
	t_wait wait = w_num;
	t_wait got;
	while (src[size])
		size ++;
	t_queue *result = create_q();
	while (++a < size)
	{
		if (src[a] != ' ')
		{
		//	probe(a, "a: ");
			got = enq(result, src, &a);
		}
		else
			continue;
		b = result->back->data;
		if (wait == got)
		{
			if (b != '(' && b != ')')
				wait ^= 1;
		}
		else
		{
			probe(a, "at index ");
			throw(wait, b, result->back->num);
			return (0);
		}
	}
	return (result);
}

void	deq(t_queue *q, int flag)
{
	t_op *f = q->front;
	if (flag && (f->type == num || f->type == alg))
		free(f->num);
	f = f->next;
	free(q->front);
	q->front = f;
	if (f == q->nil)
		q->back = f;
}

void	q_copy(t_queue *out, t_op *src, t_queue *in)
{
	t_op *back = out->back;
	out->size += 1;
	back->next = make(out->nil);
	back = back->next;
	if (out->front == out->nil)
		out->front = back;
	back->type = src->type;
	back->data = src->data;
	back->num = src->num;
	out->back = back;
	if (in)
		deq(in, 0);
}

void	push(t_stack *stack, t_queue *in)
{
	stack->top += 1;
	t_op *a = &stack->arr[stack->top];
	t_op *f = in->front;
	a->data = f->data;
	a->type = f->type;
	deq(in, 1);
}

void	r_pop(t_stack *stack, t_queue *out)
{
	int i = stack->top - 1;
	t_op *a = &stack->arr[i];
	t_op *b = &stack->arr[i + 1];
	q_copy(out, a, 0);
	a->data = b->data;
	a->type = b->type;
	stack->top -= 1;
}

void	b_pop(t_stack *stack, t_queue *out)
{
	int top = stack->top;
	int i = top;
	while (i != -1 && stack->arr[i].data != '(')
		i --;
	int k = top - i;
	i ++;
	while (i <= top)
	{
		q_copy(out, &stack->arr[i], 0);
		i ++;
	}
	stack->top -= (k + 1);
}

int		check(t_stack *stack)
{
	int top = stack->top;
	if (top < 1)
		return (0);
	t_op *s = stack->arr;
	t_op a = s[top];
	t_op b = s[top - 1];
	/*
	write(1, &b.data, 1);
	write(1, &a.data, 1);
	write(1, "\n", 1);
	*/
	if (a.type == e && b.type == e)
		return (0);
	if (b.type >= a.type && b.type != p)
		return (1);
	return (0);
}

void	empty(t_stack *stack, t_queue *out)
{
	int i = stack->top;
	while (i > -1)
		q_copy(out, &stack->arr[i--], 0);
}

t_stack	*create_s(int size)
{
	t_stack *s = malloc(sizeof(t_stack));
	s->top = -1;
	s->arr = malloc(size * sizeof(t_op));
	return (s);
}

char	*tabler(void)//remember '!' factorial
{
	char *c = malloc(128 * sizeof(char));
	int i = 0;
	while (i < 128)
		c[i++] = 0;
	c['+'] = 1;
	c['-'] = 1;
	c['/'] = 1;
	c['*'] = 1;
	c['%'] = 1;
	c['^'] = 1;
	c['('] = 1;
	c[')'] = 1;
	return (c);
}

t_queue	*ft_postfix(t_queue *in)
{
	int size = in->size;
	t_op *f = in->front;
	t_queue *out = create_q();
	t_stack *stack = create_s(size);
	char *op = tabler();
	while (f->type != nil)
	{
		if (f->type <= num)
			q_copy(out, f, in);
		else if (f->data == ')')
		{
			b_pop(stack, out);
			deq(in, 1);
		}
		else if (op[(unsigned char) f->data])
		{
			push(stack, in);
			while (check(stack))
				r_pop(stack, out);
		}
		else
		{
			write(1, &f->data, 1);
			write(1, " <- wdf\n", 8);
			return (0);
		}
		f = in->front;
	}
	empty(stack, out);
	free(stack->arr);
	free(stack);
	free(op);
	return (out);
}


void	ft_print(t_queue *q)
{
	t_op *a = q->front;
	while (a->type != nil)
	{
		if (a->type == num || a->type == alg)
			ft_putstr(a->num);
		else
			write(1, &a->data, 1);
		a = a->next;
	}
	write(1, "\n", 1);
}

void	clear_q(t_queue *q)
{
	t_op *f = q->front;
	t_op *tmp;
	while (f->type != nil)
	{
		tmp = f->next;
		if (f->type <= num)
			free(f->num);
		free(f);
		f = tmp;
	}
	free(q->nil);
	free(q);
}

char	*spaces(char *v, char *t)
{
	int i = 0;
	int k = 0;
	while (v[i])
		i ++;
	char *result = malloc(((3 * i) + 1) * sizeof(char));
	i = 0;
	while (v[i])
	{
		if (t[(unsigned char) v[i]])
		{
			if (i > 0 && v[i - 1] != ' ')
				result[k++] = ' ';
			result[k++] = v[i];
			if ((v[i] != '-' && v[i + 1] != ' ') || t[(unsigned char) v[i + 1]])
				result[k++] = ' ';
			i ++;
		}
		else
			result[k++] = v[i++];
	}
	result[k] = 0;
	return (result);
}

int		brackets(char *in)
{
	int br = 0;
	int flag = 0;
	int i = 0;

	while (in[i])
	{
		if (in[i] == '(')
		{
			br ++;
			flag = 1;
		}
		else if (in[i] == ')')
		{
			if (flag)
				return (1);
			br --;
		}
		else if (in[i] != ' ')
			flag = 0;
		i ++;
	}
	return (br);
}

int		main(int c, char **v)
{
	if (c != 2)
		return (1);
	char *table = tabler();
	char *input = spaces(v[1], table);
	ft_putstr(input);
	write(1, "\n", 1);
	if (brackets(input))
	{
		write(1, "improper brackets\n", 18);
		return (1);
	}
	t_queue *in = ft_me_dup(input);
	if (!in)
		return (1);
	ft_print(in);
	t_queue *out = ft_postfix(in);
	ft_print(out);
	free(input);
	free(table);
	clear_q(in);
	clear_q(out);
}
