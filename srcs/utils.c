#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

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

bool	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i] == 0);
}

void	free_all(t_stack *stack)
{
	if (stack->node)
		stack->node->prev->next = NULL;
	while (stack->node->next)
	{
		stack->node = stack->node->next;
		free(stack->node->prev);
		stack->node->prev = NULL;
	}
	free(stack->node);
	stack->node = NULL;
	free(stack);
	stack = NULL;
}
