#include "push_swap.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		nb;
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

void print(t_stack *stack)
{
    if (stack->node)
    for (int i = 0; i < stack->size; ++i){
        printf("%d ", stack->node->nb);
        stack->node = stack->node->next;
    }
    printf("\n");
}