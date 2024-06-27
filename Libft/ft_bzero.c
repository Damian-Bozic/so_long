/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:41:46 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/05 17:09:30 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	int	i;

	i = 0;
	while (n-- > 0)
	{
		((char *)str)[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
#include <string.h>
#include <stdio.h>
	int		i;
	int		size;
	char	c;
	char	str1[] = "If I had to guess this should work.";
	char	str2[] = "If I had to guess this should work.";

	size = 12;

	ft_bzero(str1, size);
	i = 0;
	while (i < 40)
	{
		c = str1[i];
		write(1, &c, 1);
		i++;
	}

	write(1, "\n", 1);
	bzero(str2, size);
	i = 0;
	while (i < 40)
	{
		c = str2[i];
		write(1, &c, 1);
		i++;
	}
}*/
