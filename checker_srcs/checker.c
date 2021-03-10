#include "checker.h"

void    choice(t_stack *left, t_stack *right, char *s)
{
    if (cmp(s, "sa"))
        swap_node(left, NULL);
    if (cmp(s, "sb"))
        swap_node(NULL, right);
    if (cmp(s, "ss"))
        swap_node(left, right);
    if (cmp(s, "pa"))
        transfer(left, right);
    if (cmp(s, "pb"))
        transfer(right, left);
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

void make_operations(t_stack *left, t_stack *right)
{
    char    *line;
    bool    done;

    done = true;
    while (get_next_line(0, &line))
    {
        // printf("left: "); print(left);
        // printf("line: %s\n", line);
        choice(left, right, line);
        // printf("Right: "); print(right);
        // printf("Left: "); print(left);
        // printf("-----------------------\n");
        free(line);
    }
    // printf("Result: ");print(left);
    left->node->prev->next = NULL;
    while (left->node->next)
    {
        // printf("node: %d ", left->node->nb);
        if (left->node->nb > left->node->next->nb)
        {
            done = false;
            printf("Error: %d and %d\n", left->node->nb, left->node->next->nb);
        }
        left->node = left->node->next;
        free(left->node->prev);
        left->node->prev = NULL;
    }
    // printf("node: %d ", left->node->nb);
    // if (left->node->nb > left->node->next->nb)
    //     done = false;
    free(left->node);
    left->node = NULL;
    if (done)
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
    left = init_stack(av, true);
    right = init_stack(av, false);
    make_operations(left, right);
    free(left);
    free(right);
    return 0;
}
