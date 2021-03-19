#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct      s_node
{
    int             nb;
    struct s_node   *prev;
    struct s_node   *next;
}                   t_node;

typedef struct      s_stack
{
    struct s_node   *node;
    int             size;
    int             max;
    bool            way;
    bool            value;
    bool            first_lap;
}                   t_stack;

int         ft_atoi(const char *s);
bool        cmp(char *s1, char *s2);
void        print(t_stack *stack);
void        push_front(t_stack *stack, int nb);
t_stack     *init_stack(int ac, char **av, bool main);
void        free_all(t_stack *stack);

int         get_pivot(t_stack *left, int nb);
void        max_loop(t_stack *right);
bool        is_sort(t_stack *left, int nb);


void        swap_node(t_stack *left, t_stack *right);
void        transfer(t_stack *left, t_stack *right, char *s);
void        rotate(t_stack *left, t_stack *right, bool direction);
void        choice(t_stack *left, t_stack *right, char *s);

void        split(t_stack *left, t_stack *right, int nb);
void        sort(t_stack *left, t_stack *right, int size);
void        speed_sort(t_stack *left, t_stack *right);
void        short_stack(t_stack *left, t_stack *right);


#endif