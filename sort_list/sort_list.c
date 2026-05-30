#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list  *current;
    t_list  *next;
    int     temp;
    int     swapped;

    if (!lst || !lst->next)
        return (lst);
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        current = lst;
        next = lst->next;
        while (next)
        {
            if (!cmp(current->data, next->data))
            {
                temp = current->data;
                current->data = next->data;
                next->data = temp;
                swapped = 1;
            }
            current = current->next;
            next = next->next;
        }
    }
    return (lst);
}