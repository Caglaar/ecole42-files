/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhammedemincaglar <muhammedemincaglar@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:52:49 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/08 15:16:57 by muhammedemi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int ft_strlen(char *str)
{
    int counter;

    counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}
int main ()
{
    char *sentences = "";
    int sayac = ft_strlen(sentences);
    printf("%d",sayac);
}