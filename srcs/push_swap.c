#include "push_swap.h"

void	speed_sort(t_stack *left, t_stack *right)
{
	while (right->size)
	{
		max_loop(right);
		if (right->way)
			while (right->node->nb != right->max)
				choice(left, right, "rb");
		else
			while (right->node->nb != right->max)
				choice(left, right, "rrb");
		choice(left, right, "pa");
	}
}

void	split(t_stack *left, t_stack *right, int nb)
{
	bool	pair;
	int		avg;
	int		nb_push;

	avg = get_pivot(left, nb);
	nb_push = 0;
	pair = nb % 2 == 0;
	while (nb--)
	{
		if (pair && left->node->nb <= avg)
			choice(left, right, "pb");
		else if (!pair && left->node->nb <= avg)
			choice(left, right, "pb");
		else
		{			
			choice(left, right, "ra");
			nb_push++;
		}	
	}
	while (!left->first_lap && nb_push--)
		choice(left, right, "rra");
	if (left->first_lap)
		left->first_lap = false;
}

void	short_split(t_stack *left, t_stack *right, int size)
{
	while (size--)
		choice(left, right, "pb");
}

void	sort(t_stack *left, t_stack *right, int size)
{
	int	tmp;

	tmp = size;
	if (is_sort(left, size))
	{
		if (!is_sort(left, left->size))
			while (tmp--)
				choice(left, right, "ra");
		return ;
	}
	if (size > 20)
		split(left, right, size);
	else
		short_split(left, right, size);
	if (right->size <= 27)
		speed_sort(left, right);
	while (right->node)
		choice(left, right, "pa");
	sort(left, right, size / 2);
	if (size % 2)
		size++;
	sort(left, right, size / 2);
}

int	main(int ac, char **av)
{
	t_stack	*left;
	t_stack	*right;

	if (ac < 2)
		return (1);
	left = init_stack(ac, av, true);
	right = init_stack(ac, av, false);
	if (left->size > 30)
		sort(left, right, left->size);
	else
		short_stack(left, right);
	free_all(left);
	free(right);
}
