char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i = 0;
	unsigned int d = 0;

	while (dest[d++]);

	while (src[i] && i < nb)
	{
		dest[d + i] = src[i];
		i ++;
	}
	dest[d + i] = '\0';
	return (dest);
}
