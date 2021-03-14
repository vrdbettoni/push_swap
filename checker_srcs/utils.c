#include "checker.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (int)str[i++] - '0';
	return (nb * sign);
}

bool cmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i] == 0 ? true : false);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int ft_strlen(char *s)
{
    int i;

	i = 0;
    while (s[i])
        i++;
    return i;
}

bool max_int(char *s)
{
	long test;

	test = ft_atoi(s);
	if (test > INT_MAX || test < INT_MIN)
		return (true);
	return (true);
}