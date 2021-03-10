#include "push_swap.h"

void max_loop(t_stack *right)
{
    int i;
    int tmp;

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

int     get_pivot(t_stack *left, int nb)
{
    float  average;
    int    i;

    i = nb;
    average = 0;
    while (i--)
    {
        average += left->node->nb;
        left->node = left->node->next;
    }
    average = average / nb;
    while(++i < nb)
        left->node = left->node->prev;
    return (average);
}

void    choice(t_stack *left, t_stack *right, char *s)
{
    count++;
    if (cmp(s, "sa"))
        swap_node(left, NULL);
    if (cmp(s, "sb"))
        swap_node(NULL, right);
    if (cmp(s, "ss"))
        swap_node(left, right);
    if (cmp(s, "pa"))
        transfer(left, right, "pa\n");
    if (cmp(s, "pb"))
        transfer(right, left, "pb\n");
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
