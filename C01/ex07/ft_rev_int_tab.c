#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
    int counter;
    int container;
    int size_copy;

    counter = 0;
    size_copy = size;
    while(counter < (size / 2))
    {
        container = tab[counter];
        tab[counter] = tab[size_copy-1];
        tab[size_copy-1] = container;
        counter++;
        size_copy--;
    }
}
int main ()
{
    int tab[7]={0,1,2,3,4,5,6};
    int size = 7;
    ft_rev_int_tab(tab,size);
    for (int  i = 0; i < size; i++)
    {
        printf("%d\n",tab[i]);
    }
    
}