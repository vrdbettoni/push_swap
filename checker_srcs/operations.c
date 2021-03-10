#include "checker.h"

void push_front(t_stack *stack, int nb)
{
    t_node  *new;

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
    stack->size++;
    stack->node = new;
}

t_stack *init_stack(char **av, bool main)
{
    t_stack *stack;
    int i;

    i = 1;
    stack = malloc(sizeof(t_stack));
    stack->node = NULL;
    stack->size = 0;
    while (main && av[i])
        push_front(stack, ft_atoi(av[i++]));
    return (stack);
}

void swap_node(t_stack *left, t_stack *right)
{
    int tmp;

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
}

void transfer(t_stack *left, t_stack *right)
{
    t_node *tmp;

    if (!left)
        return ;
    tmp = left->node;
    left->node->prev->next = left->node->next;
    left->node->next->prev = left->node->prev;
    left->node = left->node->next;
    push_front(right, tmp->nb);
    left->size--;    
    if (left->size == 0)
        left->node = NULL;

    free(tmp);
}

void    rotate(t_stack *left, t_stack *right, bool direction)
{
    if (direction && left)
        left->node = left->node->next;
    if (direction && right)
        right->node = right->node->next;
    if (!direction && left)
        left->node = left->node->prev;
    if (!direction && right)
        right->node = right->node->prev;
}
