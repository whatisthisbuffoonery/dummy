#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(char *v)//-1 paranoia
{
	int i = 0;
	while (v[i])
		i ++;
	return (i);
}

void	ft_error(void)
{
	char *a = strerror(errno);
	write(1, a, ft_strlen(a));
}

int		pop(int offset[], int src, int i)
{
	if (i > 9)//dodge if statement if buffer is full
		i = 0;
	if (offset[i] < 0)
	{
		offset[i] = src;
		return (0);
	}
	while (i < 9)//shift values to the left if buffer is full
	{
		offset[i] = offset[i + 1];
		i ++;
	}
	offset[i] = src;
	return (0);
}

void	parse(int fd, char buf[], int offset[])//this worked the last time around
{
	int o_i = 0;//line break count
	int i = 0;
	int tmp = 0;

	while (read(fd, buf, 1))
	{
		tmp ++;
		if (buf[0] == '\n')
		{
			pop(offset, i, o_i++);//put start of line as offsert index
			i += tmp;
			tmp = 0;
		}
	}
}

int		ft_fd(char *v, int *fd)//open files and check for fd fail
{
	*fd = open(v, O_RDONLY);
	if (*fd < 0)
	{
		ft_error();
		return (1);
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}

int		ft_atoi(char *v)
{
	int i = 0;
	int a = 0;
	while (v[i])
	{
		if (v[i] < 48 || v[i] > 57)
			return (-1);
		a *= 10;
		a += v[i] - 48;
		i ++;
	}
	if (!a)
		return (-1);//if -c flag is 0, print nothing
	return (a);
}

int		c_flag(int c, char **v)
{
	char *flag = "-c";
	int i = 1;
	int a = 0;

	while (i < c)
	{
		if (!ft_strcmp(v[i], flag))
		{
			if (i + 1 < c)
			{
				a = ft_atoi(v[i + 1]);//if 0 return -1
				while (i + 2 < c)
				{
					v[i] = v[i + 2];
					i ++;
				}
				return (a);
			}	
			else
				return (-1);//print nothing
		}
		i ++;
	}
	return (0);//no flag
}

void	baja_blast(char buf[])//not in use
{
	(void)buf;
	//x;
}

void	ft_header(char *v)
{
		write(1, "==> ", 4);
		write(1, v, ft_strlen(v));
		write(1, " <==\n", 5);
}

void	ft_flip_str(char buf[], char tmp[], int flip_count, int *size, int fd)
{
	if (flip_count % 2)			//							this cost me another 1 hour
		*size = read(fd, tmp, 1024);
	else
		*size = read(fd, buf, 1024);
}

char	*ft_strmeow(char big[], char smol[], int flag, int size_smol)//is correct so far
{
	int size_big = 1024;
	int i = 0;
	int diff;
	char *a = malloc((flag + 1) * sizeof(char));

	if (!a)
		return (NULL);
	if (size_smol < flag)
	{
		diff = flag - size_smol;
		while (i < diff)
		{
			a[i] = big[size_big - (diff - i)];
			i ++;
		}
		while (i < flag)
		{
			a[i] = smol[i - diff];
			i ++;
		}
		a[i] = '\0';
		return (a);
	}
	while (i < flag)
	{
		a[i] = smol[size_smol - (flag - i)];
		i ++;
	}
	a[i] = '\0';
	return (a);
}

int		ft_read(char *v, int flag)
{
	char buf[1024];
	char tmp[1024];
	int buf_size = 1024;
	int flip_count = 0;
	int offset[10];
	int i = 0;
	int size = 0;
	int fd = 0;
	char *a;
	while (i < 10)
		offset[i++] = -42;
	i = 0;
	if (ft_fd(v, &fd))
		return (1);
	if (!flag)
	{
		parse(fd, buf, offset);//no -c flag case
		close(fd);//reset fd pointer
		if (ft_fd(v, &fd))//reopen
			return (1);
		while (i + buf_size < offset[0])//				fucking segfault cost me 3 HOURS GODF********
		{
			read(fd, buf, buf_size);
			i += buf_size;
		}
		read(fd, buf, offset[0] - i);
		size = read(fd, buf, buf_size);//discard until first line
		write(1, buf, size);//write 10 lines
	}
	else
	{
		size = read(fd, buf, buf_size);//-c flag case
		while (size == buf_size)//if full buffer
			ft_flip_str(buf, tmp, ++flip_count, &size, fd);//start processing more data
		if (flip_count % 2 == 1)//use two buffers to obtain tail
			a = ft_strmeow(buf, tmp, flag, size);
		if (flip_count % 2 == 0)
			a = ft_strmeow(tmp, buf, flag, size);
		if (!a)
			return (1);
		write(1, a, flag);
		free(a);
	}
	close(fd);
	return (0);
}

int		main(int c, char **v)
{
	int offset[10];
	int i = 0;
	int header = 0;
	while (i < 10)//set array
		offset[i++] = -42;
	i = 1;
	int flag = c_flag(c, v);//handle -c flag
	if (flag < 0 || flag > 1024)
		return (1);
	if (flag)
		c -= 2;//-c flag takes up 2 args of space
	if (c > 2)
		header = 1;//header for multiple file args
	if (c < 2)
		return (1);//print nothing

	while (i < c)
	{
		if (header)
			ft_header(v[i]);
		if(ft_read(v[i], flag))
			return (1);//print nothing
		i ++;
		if (i < c)
			write(1, "\n", 1);
	}
}
