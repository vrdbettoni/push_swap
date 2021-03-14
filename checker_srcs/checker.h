#ifndef CHECKER_H
# define CHECKER_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct      s_node
{
    int     nb;
    struct s_node *prev;
    struct s_node *next;
}                   t_node;

typedef struct      s_stack
{
    struct s_node *node;
    int            size;
}                   t_stack;

int get_next_line(int fd, char **line);

long ft_atoi(const char *s);
bool cmp(char *s1, char *s2);
int ft_strlen(char *s);
int ft_isdigit(int c);
bool max_int(char *s);

void push_front(t_stack *stack, int nb);
t_stack *init_stack(int ac, char **av, bool main);
void swap_node(t_stack *left, t_stack *right);
void transfer(t_stack *left, t_stack *right);
void    rotate(t_stack *left, t_stack *right, bool direction);
bool    choice(t_stack *left, t_stack *right, char *s);

#endif