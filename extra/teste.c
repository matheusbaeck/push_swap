#include "limits.h"

unsigned int    utoi(int nb)
{
    unsigned int    u;

    u = 0;
    if (nb == INT_MIN)
        u = UINT_MAX;
    else if (nb < 0)
        u += INT_MAX + nb * -1;
    else if (nb > 0)
        u += nb;
    return (nb);
}

int    ft_duplicity_check(int *numbers)
{
    static int    *registry[UINT_MAX];

    while (*numbers)
    {
        if (registry[utoi(*numbers)] == 0)
            registry[utoi(*numbers)] = 42;
        else
            return (0);
    }
    return (1);
}

int main(void)
{
  int n[3];
  
  n[0] = INT_MAX;
  n[1] = INT_MIN;
  n[3] = 0;
  ft_duplicity_check(n);
  return(0);
}