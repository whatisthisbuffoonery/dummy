#include "postfix.h"

void	ft_putstr(char *a)
{
	int i = 0;
	while (a[i])
		i ++;
	write(1, a, i);
}

void	ft_putnbr(long n)
{
	long t = 1;
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

int		ft_atoa(t_op *op, char *src, int *index, int *complain)
{
	int i = *index;
	int k = 0;
	int flag = 0;
	int fnum = 0;
	if (src[i] == '-')
		ft_putstr("poopy\n");
	while (src[i] && src[i] != ' ')
		i ++;
	k = i - *index;
	op->num = malloc((k + 1) * sizeof(char));
	i = *index;
	k = 0;
	while (src[i + k] && src[i + k] != ' ')
	{
		op->num[k] = src[i + k];
		if (op->num[k] > '9')
			flag = 1;
		else
			fnum = k + 1;
		k ++;
	}
	op->num[k] = 0;
	if (flag)
		op->type = alg;
	if (flag && k > 1)
	{
		if (fnum)
			*complain = 1;
		else
			op->mul = 1;
	}
	*index += k;
	return (fnum * flag);
}

t_op	*make(t_op *n)
{
	t_op *a = malloc(sizeof(t_op));
	if (!n)
		n = a;
	a->next = n;
	a->type = nil;
	a->num = 0;
	a->result = 0;
	a->data = 0;
	a->mul = 0;
	return (a);
}

t_op	*fudge_mul(t_op *nil)
{
	t_op *a = make(nil);
	a->data = '*';
	a->type = md;
	return (a);
}
//wtf you mean the user put two funcs together without brackets
void	ft_func_fudge(t_queue *q, t_op *op)
{
	t_op *tmp = op->next;//update back if nil
	t_op *f = op;
	int i = 1;
	f->mul = 0;
	/*
	ft_putstr("num: ");
	ft_putstr(op->num);
	write(1, "\n", 1);
	*/
	int k = 0;
	if (op->num)
	{
		while (op->num[k])
			k ++;
	}
	while (i < k)
	{
		f->next = fudge_mul(q->nil);
		f = f->next;
//		probe(f->type, "hear: ");
		f->next = make(q->nil);
		f = f->next;
		f->num = malloc(2 * sizeof(char));
		f->num[0] = op->num[i];
		f->num[1] = 0;
		if (f->num[0] > '9')
			f->type = alg;
		else
			f->type = num;
//		probe(f->type, "hear: ");
		i ++;
		q->size += 2;
	}
	if (k > 1)
		op->num[1] = 0;
	if (tmp->type == nil)
		q->back = f;
	else if (i == 1)
	{
		q->size += 1;
		if (f->type == num || f->type == p)
		{
			f->next = fudge_mul(q->nil);
			f = f->next;
		}
	}
	if (tmp->type != nil)
		f->next = tmp;
}

t_wait	enq(t_queue *q, char *src, int *index)
{
	int i = *index;
	int complain = 0;
	char c = src[i];
	t_op *back = q->back;
	back->next = make(q->nil);
	back = back->next;
	q->size += 1;
	switch (c)
	{
		case '-':
		case '+':
			back->type = as;
			break;
		case '!':
			back->type = fac;
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
		if (ft_atoa(back, src, index, &complain) > 1)
			return(err);
		if (complain)
			ft_func_fudge(q, back);
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

void	throw(t_wait wait, t_op *f, char *src, int size, char *err_msg)
{
	char b = f->data;
	char *str = f->num;
	ft_putstr(src);
	write(1, "\n", 1);
	int a = (wait == op) + (wait == err);
	while (a < size)
	{
		a++;
		write(1, " ", 1);
	}
	write(1, "^\n", 2);
	probe(size, "at index ");
	if (err_msg)
	{
		ft_putstr(err_msg);
		write(1, "\n", 1);
		return;
	}
	write(1, "expecting ", 10);
	if (wait == w_num)
		write(1, "operand, ", 9);
	else
		write(1, "operator, ", 10);
	write(1, "got: ", 5);
	if (!str)
		write(1, &b, 1);
	else
		ft_putstr(str);
	write(1, "\n", 1);
}

void	clear_q_soft(t_queue *q)
{
	t_op *f = q->front;
	t_op *tmp;
	while (f->type != nil)
	{
		tmp = f->next;
		free(f);
		f = tmp;
	}
	free(q->nil);
	free(q);
}

void	clear_q_hard(t_queue *q)
{
	t_op *f = q->front;
	t_op *tmp;
	while (f->type != nil)
	{
		tmp = f->next;
		if (f->type <= num || f->type == una || f->type == fun)
			free(f->num);
		free(f);
		f = tmp;
	}
	free(q->nil);
	free(q);
}

void	ft_una(t_queue *q)
{
	t_op *back = q->back;
	back->type = una;
	back->num = malloc(3 * sizeof(char));
	char *c = back->num;
	c[0] = '_';
	c[1] = 'u';
	c[2] = 0;
}

void	ft_func(t_op *f)
{
	f->type = fun;
	f->mul = 0;
}

void	ft_mul(t_queue *q)
{
	t_op *f = q->front;
	while (f->type != nil)
	{
		if (f->mul)
			ft_func_fudge(q, f);
		f = f->next;
	}
}

t_queue	*ft_me_dup(char *src)
{
	int a = -1;
	int size = 0;
	char b;
	t_wait wait = w_num;
	t_wait got;
	t_type type;
	t_op *back;
	while (src[size])
		size ++;
	t_queue *result = create_q();
	while (++a < size)
	{
		back = result->back;
		type = back->type;
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
			if ((b != '(' && b != ')') && b != '!')
				wait ^= 1;
		}
		else if (got == err)
		{
			throw(err, result->back, src, a, "jumbled numbers and letters\n");
			clear_q_hard(result);
			return (0);
		}
		else if ((wait == w_num && b == '-') && type != una)
			ft_una(result);
		else if ((wait == op && b == '(') && type <= num)
		{
			wait ^= 1;
			if (type == alg)
				ft_func(back);
			else if (type == num)
				ft_func_fudge(result, back);
		}
		else if (wait == op && back->data == ')' && (result->back->type == alg || result->back->data == '('))
		{
			if (result->back->data == '(')
				wait = w_num;
			ft_func_fudge(result, back);
		}
		else
		{
			throw(wait, result->back, src, a, 0);
			clear_q_hard(result);
			return (0);
		}
	}
	if (wait == w_num)
	{
		if (result->size)
			throw(wait, result->back, src, a, "missing operand at end of string\n");
		else
			ft_putstr("empty string\n");
		clear_q_hard(result);
		return (0);
	}
	ft_mul(result);
	return (result);
}

void	q_copy(t_queue *out, t_op *src)
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
}

void	push(t_stack *stack, t_op *f)
{
	stack->top += 1;
	t_op *a = &stack->arr[stack->top];
	a->data = f->data;
	a->num = f->num;
	a->type = f->type;
	a->result = f->result;
//	probe(a->result, "push: ");
}

void	r_pop(t_stack *stack, t_queue *out)
{
	int i = stack->top - 1;
	t_op *a = &stack->arr[i];
	t_op *b = &stack->arr[i + 1];
	q_copy(out, a);
	a->data = b->data;
	a->type = b->type;
	a->num = b->num;
	stack->top -= 1;
}

void	b_pop(t_stack *stack, t_queue *out)
{
	int top = stack->top;
	int i = top;
	while (i != -1 && stack->arr[i].data != '(')
		i --;
	int k = top - i;
	while (top > i)
	{
		q_copy(out, &stack->arr[top]);
		top --;
	}
	stack->top -= (k + 1);
}

int		check(t_stack *stack)
{
	int flag = 0;
	int top = stack->top;
	if (top < 1)
		return (0);
	t_op *s = stack->arr;
	t_op a = s[top];
	t_op b = s[top - 1];
	int a_t = a.type - (a.type == una);
	int b_t = b.type - (b.type == una);
	if (a_t == b_t && a.type >= e)
		flag = 0;
	else if (b_t >= a_t && b.type != p)
		flag = 1;
	/*	
	write(1, &b.data, 1);
	write(1, &a.data, 1);
	probe(flag, "decision: ");
	write(1, "\n", 1);
	*/
	return (flag);
}

void	empty(t_stack *stack, t_queue *out)
{
	int i = stack->top;
	while (i > -1)
	{
		/*
		write(1, "push: ", 6);
		write(1, &stack->arr[i].data, 1);
		write(1, "\n", 1);
		*/
		q_copy(out, &stack->arr[i--]);
	}
}

t_stack	*create_s(int size)
{
	t_stack *s = malloc(sizeof(t_stack));
	s->top = -1;
	s->arr = malloc(size * sizeof(t_op));
	return (s);
}

char	*tabler(void)
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
	c['!'] = 1;
	c['^'] = 1;
	c['('] = 1;
	c[')'] = 1;
	return (c);
}

void	clear_s(t_stack *s)
{
	free(s->arr);
	free(s);
}

t_queue	*postfix_convert(t_queue *in)
{
	int size = in->size;
	t_op *f = in->front;
	t_queue *out = create_q();
	t_stack *stack = create_s(size);
	char *op = tabler();
	while (f->type != nil)
	{
		if (f->type <= num)
			q_copy(out, f);
		else if (f->data == ')')
			b_pop(stack, out);
		else if (f->type == fun || op[(unsigned char) f->data])
		{
			push(stack, f);
			while (check(stack))
				r_pop(stack, out);
		}
		else
		{
			write(1, &f->data, 1);
			write(1, " <- wdf\n", 8);
			return (0);
		}
		f = f->next;
	}
	empty(stack, out);
	clear_s(stack);
	free(op);
	return (out);
}

void	ft_print(t_queue *q)
{
	t_op *a = q->front;
	while (a->type != nil)
	{
		if (a->num)
			ft_putstr(a->num);//propose clearing una here
		else
			write(1, &a->data, 1);
		a = a->next;
	}
	write(1, "\n", 1);
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
			if (v[i + 1] != ' ' && !t[(unsigned char) v[i + 1]])
				result[k++] = ' ';
			i ++;
		}
		else if (v[i] == '\\')
		{
			i ++;
			result[k++] = ' ';
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

int		spelling(char *in, char *t)
{
	int i = 48;
	while (i < 58)
		t[i++] = 1;
	i = 65;
	while (i < 91)
		t[i++] = 1;
	i = 97;
	while (i < 123)
		t[i++] = 1;
	t[' '] = 1;
	i = 0;
	while (in[i])
	{
		if (!t[(unsigned char) in[i]])
			return (1);
		i ++;
	}
	return (0);
}

t_queue *ft_postfix(char *v)
{
	char *table = tabler();
	char *input = spaces(v, table);
	t_queue *in = 0;
	t_queue *out = 0;
//	ft_putstr(input);
	write(1, "\n", 1);
	if (brackets(input))
		write(1, "improper brackets\n", 18);
	else if (spelling(input, table))
		write(1, "unrecognised chars found\n", 25);
	else
		in = ft_me_dup(input);
	if (in)
	{
//		ft_print(in);
		out = postfix_convert(in);
		ft_print(out);
		clear_q_soft(in);
	}
	free(input);
	free(table);
	return (out);
}

int		ft_atoi(char *c)
{
	int i = 0;
	int a = 0;
	int flag = 1;
	if (c[i] == '-')
	{
		flag = -1;
		i ++;
	}
	while (c[i])
	{
		a *= 10;
		a += c[i] - 48;
		i ++;
	}
	return (a * flag);
}

int		ft_alg(t_queue *in)
{
	if (!in)
		return (1);
	t_op *f = in->front;
	while (f->type != nil)
	{
		if (f->type == alg || f->type == fun)
		{
			ft_putstr("algebra/functions present, do not calc\n");
			return (1);
		}
		else if (f->type == num)
			f->result = ft_atoi(f->num);
		f = f->next;
	}
	return (0);
}

int		ft_iterative_power(int nb, int power)
{
	int a = 1;
	if (power < 0)
		return (0);
	while (power--)
		a *= nb;
	return (a);
}

int		ft_div(int a, int b, char op)
{
	int i = a / b;
	if (op == '/')
		return (i);
	i *= b;
	return (a - i);
}

int		ft_iterative_factorial(int nb)
{
	int a = nb;

	if (nb < 0)
		return (0);
	if (!nb)
		return (1);
	while (--nb)
		a *= nb;
	return (a);
}

void	do_op(t_stack *s, t_op *ape, int *complain)
{
	int top = s->top;
	int flag = 1;
	t_op *a = &s->arr[top - 1];
	t_op *b = &s->arr[top];
	char op = ape->data;
//	probe(a->result, "a: ");
//	probe(b->result, "b: ");
//	ft_putstr(&op);
//	write(1, "\n", 1);
	switch (op)
	{
		case '+':
			a->result += b->result;
			break;
		case '-':
			if (ape->type == una)
			{
				b->result = 0 - b->result;
				flag = 0;
			}
			else
				a->result -= b->result;
			break;
		case '*':
			a->result *= b->result;
			break;
		case '^':
			if (b->result < 1)
			{
				write(1, "sorry, no floats or fractional monads here (negative power error)\n", 66);
				*complain = 1;
				return;
			}
			a->result = ft_iterative_power(a->result, b->result);
			break;
		case '!':
			if (b->result < 0)
			{
				write(1, "factorial of negative number\n", 29);
				*complain = 1;
				return;
			}
			b->result = ft_iterative_factorial(b->result);
			flag = 0;
			break;
		case '/':
		case '%':
			if (b->result == 0)
			{
				write(1, "division/modulo by 0\n", 21);
				*complain = 1;
				return;
			}
			a->result = ft_div(a->result, b->result, op);
	}
	s->top -= flag;
}

long	ft_calc(char *v, int *complain)
{
	int a = 0;
	t_queue *in = ft_postfix(v);
	if (ft_alg(in))
	{
		if (in)
			clear_q_hard(in);
		*complain = 1;
		return (0);
	}
	t_stack *s = create_s(in->size);
	t_op *f = in->front;
	while (f->type != nil)
	{
		if (f->type == num)
			push(s, f);//leaving a deq() in push was REALLY bad design
		else
			do_op(s, f, complain);
		if (*complain)
			break;
		f = f->next;
	}
	a = s->arr[s->top].result;
	clear_s(s);
	clear_q_hard(in);
	return (a);
}

void	dialogue(char *v)
{
	ft_putstr("usage: ");
	ft_putstr(v);
	ft_putstr(" \"...\"\n");
	ft_putstr("recognised operators:\n");
	int i = 0;
	char *table = tabler();
	while (i < 128)
	{
		if (table[i])
		{
			ft_putstr((char *) &i);
			ft_putstr("\n");
		}
		i ++;
	}
	ft_putstr("functions are allowed i.e. f(x), sin(y)\n\n");
	ft_putstr("implicit multiplication allowed to reasonable extent: 2n, (2)n, 2(n), but not n2, (n)2, n(2) is a func\n\n");
	ft_putstr("allowed operands: numbers and single chars\n\n");
	ft_putstr("backslashes OK for dealing with bash\n\n");
	ft_putstr("exact change for division: no refunds (no floats in here)\n\n");
	ft_putstr("no negative powers either\n\n");
	ft_putstr("helpful debug logs:\n");
	ft_putstr("113: fudge input\n" \
			"207: probe enqueue\n" \
			"329: other half of probe enqueue\n" \
			"404: probe stack push\n" \
			"449: stack decision\n" \
			"464: empty contents\n" \
			"630: ft_postfix input/output verification\n" \
			"733: check calculation\n" \
			"\n");
	free(table);
}

int		main(int c, char **v)
{
	if (c != 2)
	{
		dialogue(v[0]);
		return (0);
	}
	int complain = 0;
	long a = ft_calc(v[1], &complain);
	if (!complain)
		ft_putnbr(a);
	write(1, "\n", 1);
	return (complain);
}
