unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i = 0;
	unsigned int b = size - 1;
	unsigned int s = 0;

	while (src[s++]);
	s --;
	if (!size)
		return (s);
	while (i < b && src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (s);
}
