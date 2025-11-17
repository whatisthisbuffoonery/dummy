#ifndef MCS_H
# define MCS_H

# include <unistd.h>
# include <stdlib.h>
# include <threads.h>
# include <stdatomic.h>

typedef struct						s_wait
{
	_Atomic (struct s_wait *)		next;
	atomic_char						locked;
//	int								index;
}									t_wait;

typedef struct						s_node
{
	_Atomic (struct s_node *)		next;
	atomic_int						data;
//	int								index;
}									t_node;

typedef struct						s_list
{
	_Atomic (struct s_list *)		next;
	_Atomic (t_node *)				arr;
//	int								index;
}									t_list;


typedef struct
{
	_Atomic (t_list *)				list;
	_Atomic (t_node *)				arr;
	_Atomic (t_list *)				l_curr;
	_Atomic (t_node *)				back;
	_Atomic (t_node *)				front;
	atomic_int						size;
	atomic_int						curr_back;
	atomic_int						curr_front;
}									t_queue;

#endif
