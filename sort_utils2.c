#include "push_swap.h"
void switch_op(t_stack *stack, char c, int *num)
{
        if (c == 'r')
        {
                (*num)++;
                rrotate(stack, 1);
        }
        else if (c == 'R')
        {
                (*num)--;
                rotate(stack, 1);
        }
}

void op_rr(t_stack *a, t_stack *b, int *x, int *y)
{
        (*x)++;
        (*y)++;
        rrr(a, b);
}


void op_r(t_stack *a, t_stack *b, int *x, int *y)
{
        (*x)--;
        (*y)--;
        rr(a, b);
}
