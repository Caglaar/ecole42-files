/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhammedemincaglar <muhammedemincaglar@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:20:03 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/08 15:12:11 by muhammedemi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
    int counter;

    counter = 0;
    while (str[counter] != '\0')
    {
        write(1, &str[counter], 1);
        counter++;
    }
    
}

int main()
{
    char *sentence = "ABBBAS";
    ft_putstr(sentence);
}