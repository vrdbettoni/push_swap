#include "push_swap.h"

void stack_of_three(t_stack *left, t_stack *right)
{
    if (left->node->nb < left->node->next->nb) // 123 132 231
    {
        if (left->node->nb < left->node->prev->nb)
        {
            choice(left, right, "rra");
            choice(left, right, "sa");
        }
        else if (left->node->nb > left->node->prev->nb)
            choice(left, right, "rra");
    }
    else // 312 321 213
    {
        if (left->node->next->nb < left->node->prev->nb)
        {
            if (left->node->nb > left->node->prev->nb) // 312
                choice(left, right, "ra");
            else // 213
                choice(left, right, "sa");
        }
        else
        {
            choice(left, right, "sa");
            choice(left, right, "rra");
        }
    }
}

int find_max(t_stack *left, int max, bool set)
{
    int ret;
    int size;

    ret = 0;
    size = left->size;
    ret = left->node->nb;
    if (set && ret == max)
        ret = left->node->next->nb;
    while (size--)
    {
        if (left->node->nb > ret)
        {
            if (set && left->node->nb != max)
                ret = left->node->nb;
            if (!set)
                ret = left->node->nb;
        }
        left->node = left->node->next;
    }
    return (ret);
}

void smart_rotate(t_stack *left, t_stack *right, bool bol)
{
    if (bol)
    {
        if (left->node->nb > left->node->next->nb)
            choice(left, right, "rr");
        else
            choice(left, right, "rb");
    }
    else
    {
        if (left->node->nb > left->node->next->nb)
            choice(left, right, "rrr");
        else
            choice(left, right, "rrb");
    }
}

void other_stack(t_stack *left, t_stack *right)
{
    int max[2];

    max[0] = find_max(left, 0, false);
    max[1] = find_max(left, max[0], true);
    while (left->size > 2)
    {
        if (left->node->nb != max[0] && left->node->nb != max[1])
            choice(left, right, "pa");
        else
            choice(left, right, "ra");
    }
    while (right->size)
    {
        // debug(left, right, "begin loop:");
        max_loop(right);
        if (right->way)
            while (right->node->nb != right->max)
                smart_rotate(left, right, true);
        else
            while (right->node->nb != right->max)
                smart_rotate(left, right, false);
        if (left->node->nb > left->node->next->nb)
            choice(left, right, "ra");
        choice(left, right, "pb");
    }
}

void short_stack(t_stack *left, t_stack *right)
{
    if (left->size == 2)
    {
        if (left->node->nb > left->node->next->nb)
            choice(left, right, "ra");
    }
    else if (left->size == 3)
        stack_of_three(left, right);
    else
        other_stack(left,right);
}