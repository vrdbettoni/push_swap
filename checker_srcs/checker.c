#include "checker.h"

bool    duplicate_number(t_stack *left)
{
    int i;
    bool err;

    i = left->size;
    err = false;
    while (i--)
    {
        if (left->node->nb == left->node->next->nb)
            return true;
        left->node = left->node->next;
    }
    if (err)
    {
        left->node->prev->next = NULL;
        while (left->node->next)
        {
            left->node = left->node->next;
            free(left->node->prev);
            left->node->prev = NULL;
        }
        free(left->node);
        left->node = NULL;
    }
    return false;
}

bool     input_error(int ac, char **av)
{
	int		size;
	int		i;
	char	c;

	while ( --ac > 0)
	{
		i = 0;
		size = ft_strlen(av[ac]);
		while (i < size)
		{
			c = av[ac][i];
			if (i == 0 && (c == '+' || c == '-') && !(c = av[ac][++i]))
				return (true);
			if (!ft_isdigit(c))
				return (true);
			i++;
		}
        if (max_int(av[ac]))
				return (true);
	}
	return (false);
}

bool    choice(t_stack *left, t_stack *right, char *s)
{
    if (cmp(s, "sa"))
        swap_node(left, NULL);
    else if (cmp(s, "sb"))
        swap_node(NULL, right);
    else if (cmp(s, "ss"))
        swap_node(left, right);
    else if (cmp(s, "pb"))
        transfer(left, right);
    else if (cmp(s, "pa"))
        transfer(right, left);
    else if (cmp(s, "ra"))
        rotate(left, NULL, true);
    else if (cmp(s, "rb"))
        rotate(NULL, right, true);
    else if (cmp(s, "rr"))
        rotate(left, right, true);
    else if (cmp(s, "rra"))
        rotate(left, NULL, false);
    else if (cmp(s, "rrb"))
        rotate(NULL, right, false);
    else if (cmp(s, "rrr"))
        rotate(left, right, false);
    else
        return true;
    return false;
}

void make_operations(t_stack *left, t_stack *right, bool done)
{
    char    *line;
    bool    err;

    while (get_next_line(0, &line))
    {
        err = choice(left, right, line);
        free(line);
    }
    free(line);
    left->node->prev->next = NULL;
    while (left->node->next)
    {
        if (left->node->nb > left->node->next->nb)
            done = false;
        left->node = left->node->next;
        free(left->node->prev);
        left->node->prev = NULL;
    }
    free(left->node);
    left->node = NULL;
    if (err)
        write(1, "Error\n", 6);
    else if (done)
        write(1, "[OK]\n", 5);
    else
        write(1, "[KO]\n", 5);
}

int main(int ac, char **av)
{
    t_stack *left;
    t_stack *right;

    if (ac < 2)
        return (1);
    if (input_error(ac, av))
        return (write(1, "Error\n", 6));
    left = init_stack(ac, av, true);
    right = init_stack(ac, av, false);
    if (duplicate_number(left))
        return (write(1, "Error\n", 6));
    make_operations(left, right, true);
    free(left);
    free(right);
    return 0;
}
