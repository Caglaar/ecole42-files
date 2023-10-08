/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:31:02 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 12:31:04 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

char	*ft_sj(char const *s1, char const *s2);
void	*ft_free_stash(char **stash, int create_line);
char	*get_next_line(int fd);
int		ft_have_nl(char *s);

#endif
