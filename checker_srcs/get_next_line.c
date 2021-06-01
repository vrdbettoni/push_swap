#include "checker.h"

char	*ft_strjoin_mod(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j++])
		i++;
	res = malloc(sizeof(*res) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

int	ft_strchr_mod(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_read(int fd, char **res, char *buffer, int j)
{
	int		i;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		i = ft_strchr_mod(*res);
		if (i != -1)
			break ;
		ret = read(fd, buffer, 5);
		buffer[ret] = '\0';
		*res = ft_strjoin_mod(*res, buffer);
		if (!(*res))
			return (-1);
	}
	if (i != -1)
		(*res)[i] = '\0';
	if (ret > 0 && i != -1)
	{
		i = ft_strchr_mod(buffer);
		while (buffer[i])
			buffer[j++] = buffer[1 + i++];
		buffer[j] = '\0';
	}
	return (ret);
}

int	ft_rest(char *res, char *buffer)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res[i] = '\0';
	while (i-- > 0)
		res[i] = buffer[i];
	i = ft_strchr_mod(buffer);
	if (i != -1)
	{
		if (buffer[i] == '\n')
			i++;
		while (buffer[i])
			buffer[j++] = buffer[i++];
		buffer[j] = '\0';
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line, int i)
{
	static char		*buffer;
	char			*res;

	if (!line || read(fd, 0, 0))
		return (-1);
	res = malloc(sizeof(char) * (5 + 1));
	if (!res)
		return (-1);
	res[0] = '\0';
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (5 + 1));
		if (!buffer)
			return (-1);
		i = ft_read(fd, &res, buffer, 0);
	}
	else if (ft_rest(res, buffer) == 0)
		i = ft_read(fd, &res, buffer, 0);
	*line = res;
	if (i > 0)
		return (1);
	free(buffer);
	if (i == 0)
		return (0);
	return (-1);
}
