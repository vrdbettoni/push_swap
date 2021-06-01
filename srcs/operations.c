#include "push_swap.h"

void	push_front(t_stack *stack, int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->nb = nb;
	if (stack->node)
	{
		new->prev = stack->node->prev;
		new->next = stack->node;
		stack->node->prev->next = new;
		stack->node->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	stack->node = new;
	stack->size++;
}

t_stack	*init_stack(int ac, char **av, bool main)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->size = 0;
	stack->node = NULL;
	stack->first_lap = true;
	stack->value = true;
	while (main && --ac)
		push_front(stack, ft_atoi(av[ac]));
	return (stack);
}

void	swap_node(t_stack *left, t_stack *right)
{
	int	tmp;

	tmp = 0;
	if (left)
	{
		tmp = left->node->nb;
		left->node->nb = left->node->next->nb;
		left->node->next->nb = tmp;
	}
	if (right)
	{
		tmp = right->node->nb;
		right->node->nb = right->node->next->nb;
		right->node->next->nb = tmp;
	}
	if (left && right)
		write (1, "ss\n", 3);
	else if (left)
		write (1, "sa\n", 3);
	else if (right)
		write (1, "sb\n", 3);
}

void	transfer(t_stack *left, t_stack *right, char *s)
{
	t_node	*tmp;

	if (!left)
		return ;
	tmp = left->node;
	left->node->prev->next = left->node->next;
	left->node->next->prev = left->node->prev;
	left->node = left->node->next;
	push_front(right, tmp->nb);
	left->size--;
	if (!left->size)
		left->node = NULL;
	free(tmp);
	write(1, s, 3);
}

void	rotate(t_stack *left, t_stack *right, bool direction)
{
	if (direction && left)
		left->node = left->node->next;
	if (direction && right)
		right->node = right->node->next;
	if (direction && left && right)
		write (1, "rr\n", 3);
	else if (direction && left)
		write (1, "ra\n", 3);
	else if (direction && right)
		write (1, "rb\n", 3);
	if (!direction && left)
		left->node = left->node->prev;
	if (!direction && right)
		right->node = right->node->prev;
	if (!direction && left && right)
		write (1, "rrr\n", 4);
	else if (!direction && left)
		write (1, "rra\n", 4);
	else if (!direction && right)
		write (1, "rrb\n", 4);
}
