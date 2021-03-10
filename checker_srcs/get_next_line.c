/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroth-di <vroth-di@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:14:32 by vroth-di          #+#    #+#             */
/*   Updated: 2021/03/09 16:06:29 by vroth-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	if (!(res = (char*)malloc(sizeof(*res) * (i + 1))))
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

int		ft_strchr_mod(char *s)
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

int		ft_read(int fd, char **res, char *buffer)
{
	int		i;
	int		j;
	int		ret;

	j = 0;
	ret = 1;
	while (((i = ft_strchr_mod(*res)) == -1) && ret > 0)
	{
		ret = read(fd, buffer, 5);
		buffer[ret] = '\0';
		if ((*res = ft_strjoin_mod(*res, buffer)) == NULL)
			return (-1);
	}
	(i != -1) ? (*res)[i] = '\0' : 0;
	if (ret > 0 && i != -1)
	{
		i = ft_strchr_mod(buffer);
		while (buffer[i])
			buffer[j++] = buffer[1 + i++];
		buffer[j] = '\0';
	}
	return (ret);
}

int		ft_rest(char *res, char *buffer)
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
		(buffer[i] == '\n') ? i++ : 0;
		while (buffer[i])
			buffer[j++] = buffer[i++];
		buffer[j] = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer;
	char			*res;
	int				i;

	i = 1;
	if (!line || read(fd, 0, 0) ||
							!(res = malloc(sizeof(char) * (5 + 1))))
		return (-1);
	res[0] = '\0';
	if (!buffer)
	{
		if (!(buffer = (char*)malloc(sizeof(char) * (5 + 1))))
			return (-1);
		i = ft_read(fd, &res, buffer);
	}
	else
		ft_rest(res, buffer) == 0 ? i = ft_read(fd, &res, buffer) : 0;
	*line = res;
	if (i > 0)
		return (1);
	free(buffer);
	buffer = NULL;
	if (i == 0)
		return (0);
	return (-1);
}
