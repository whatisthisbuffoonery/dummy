unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i = 0;
	unsigned int d = 0;
	unsigned int b = size - 1;

	while (dest[d++] && d < size);
	while (src[i++]);
	if (d >= size)
		return (size + i);
	i = 0;

	while (src[i] && d + i < b)
	{
		dest[d + i] = src[i];
		i ++;
	}
	dest[d + i] = '\0';
	return (d + i);
}
