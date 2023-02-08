#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
    int temp;
    int counter;
    int counter2;

    counter =0;
    while (counter < size)
    {
        counter2 = counter + 1;
        while (counter2 < size)
        {
            if (tab[counter] > tab[counter2])
            {
                temp = tab[counter2];
                tab[counter2] = tab[counter];
                tab[counter] = temp;
            }
            counter2++;
        }
        counter++;
    }
}

int main ()
{
    int arr[7]={7,10,6,3,4,2,5};
    int size    =7;
    ft_sort_int_tab(arr,size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}