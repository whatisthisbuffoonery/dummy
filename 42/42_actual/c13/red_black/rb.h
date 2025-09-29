#ifndef RB_H
# define RB_H

typedef enum
{
	red,
	black
}					lmao;

typedef struct		child
{
	struct child	*L;
	struct child	*R;
	lmao			colour;
	void			*data;
}					node;

#endif
