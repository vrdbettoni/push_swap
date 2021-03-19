#include "push_swap.h"

void max_loop(t_stack *right)
{
    int i;
    int tmp;

    tmp = 0;
    right->way = true;
    i = right->size;
    right->max = right->node->nb;
    while (i--)
    {
        if (right->max < right->node->nb)
        {
            right->max = right->node->nb;
            tmp = right->size - i;
        }
        right->node = right->node->next;  
    }
    if (tmp > right->size / 2)
        right->way = false;
}

bool    is_sort(t_stack *left, int nb)
{
    int i;
    bool ret;

    ret = true;
    i = nb;
    while (--i)
    {
        if (left->node->nb > left->node->next->nb)
            ret = false;
        left->node = left->node->next;  
    }
    while (++i < nb)
        left->node = left->node->prev;  
    return ret;
}

int     next_min(t_stack *left, int nb, int prev, bool first)
{
    int     ret;
    t_node *tmp;

    tmp = left->node;
    ret = INT_MAX;
    while (nb--)
    {
        if (first && tmp->nb < ret)
            ret = tmp->nb;
        if (!first && tmp->nb < ret && tmp->nb > prev)
            ret = tmp->nb;
        tmp = tmp->next;
    }
    return (ret);
}

int     get_pivot(t_stack *left, int nb)
{
    int     pivot;
    int     count;
    
    count = nb / 2;
    pivot = 0;
    while (count)
    {
        if (count == nb / 2)
            pivot = next_min(left, nb, pivot, true);
        else
            pivot = next_min(left, nb, pivot, false);
        --count;
        // printf("[%d]TMP = %d\n", count, pivot);
    }
    // printf("PIVOT = %d\n", pivot);
    return (pivot);
}

void    choice(t_stack *left, t_stack *right, char *s)
{
    if (cmp(s, "sa"))
        swap_node(left, NULL);
    if (cmp(s, "sb"))
        swap_node(NULL, right);
    if (cmp(s, "ss"))
        swap_node(left, right);
    if (cmp(s, "pb"))
        transfer(left, right, "pb\n");
    if (cmp(s, "pa"))
        transfer(right, left, "pa\n");
    if (cmp(s, "ra"))
        rotate(left, NULL, true);
    if (cmp(s, "rb"))
        rotate(NULL, right, true);
    if (cmp(s, "rr"))
        rotate(left, right, true);
    if (cmp(s, "rra"))
        rotate(left, NULL, false);
    if (cmp(s, "rrb"))
        rotate(NULL, right, false);
    if (cmp(s, "rrr"))
        rotate(left, right, false);
}

void free_all(t_stack *stack)
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