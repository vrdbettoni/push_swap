#include "push_swap.h"
bool a = false;

void debug(t_stack *left, t_stack *right, char *s)
{
    printf("-------------------------------------\n");
    printf("%s:\n", s);
    if (left){
        printf("Left: ");
        if (left->node){
            for (int i = 0; i < left->size; ++i){
                printf("%d ", left->node->nb);
                left->node = left->node->next;
            }
        }
    printf("\n");
    }
    if (right){
        printf("Right: ");
        if (right->node){
            for (int i = 0; i < right->size; ++i){
                printf("%d ", right->node->nb);
                right->node = right->node->next;
            }
        }
    printf("\n-------------------------------------\n");
    }
}
void    speed_sort(t_stack *left, t_stack *right)
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

void    split(t_stack *left, t_stack *right, int nb)
{
    int avg = get_pivot(left, nb);
    int nb_push = 0;
    bool pair;

    pair = nb % 2 == 0 ? true : false;
    if (a) write(1, "In Split\n", 9);
    while (nb--)
    {
        if (pair && left->node->nb <= avg)
            choice(left, right, "pb");
        else if (!pair && left->node->nb < avg)
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

void    sort(t_stack *left, t_stack *right, int size)
{
    int tmp = size;

    if (a)sleep(1);
    if(a) printf("###############################\n");
    if (a) printf("New lap with size %d\n", size);
    if (is_sort(left, size))
    {
        if (a) printf("IT'S SORT\n");
        if (!is_sort(left, left->size))
            while (tmp--)
                choice(left, right, "ra");
        return;
    }
    if(a) debug(left, right, "At start");
    split(left, right, size);
    if(a) debug(left, right, "After Split");
    if (right->size <= 27){
        speed_sort(left, right);
        if(a) debug(left, right, "After short sort");
    }
    while (right->node)
        choice(left, right, "pa");
    if(a) debug(left, right, "Before next loop");
    sort(left, right, size / 2);
    if (size % 2)
        size++;
    sort(left, right, size / 2);
}

int main(int ac, char **av)
{
    t_stack *left;
    t_stack *right;

    count = 0;
    if (ac < 2)
        return (1);
    left = init_stack(ac, av, true);
    right = init_stack(ac, av, false);
    if (a) debug(left, right, "At start:");
// debug(left, right, "At start:");
    if (left->size > 30)
        sort(left, right, left->size);
    else 
        short_stack(left, right);
    // if (left->node->nb > left->node->next->nb)
        // choice(left, right, "ra");
    // debug(left, right, "End:");
    // printf("\n[ %d ]\n", count);
    // return count;
}