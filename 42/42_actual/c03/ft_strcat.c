char	*ft_strcat(char *dest, char *src)
{
	int i = 0;
	int d = 0;

	while (dest[d++]);

	while (src[i])
	{
		dest[d + i] = src[i];
		i ++;
	}
	dest[d + i] = '\0';
	return (dest);
}
