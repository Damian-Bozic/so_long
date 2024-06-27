/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:12:11 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/06 15:11:39 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*rtn_ptr;
	size_t	i;

	i = nmemb * size;
	if (i && i / nmemb != size)
		return (0);
	rtn_ptr = malloc(i);
	if (!rtn_ptr)
		return (0);
	ft_bzero(rtn_ptr, i);
	return (rtn_ptr);
}
//size_t * size_t protection incase your calloc is used at nasa.

/*int	main(void)
{
#include <stdlib.h>
#include <stdio.h>
	int		i;
	char	c;
	int		nmemb = 4;
	int		size = 20;
	char	*ptr;

	write(1, "new1", 4);
	ptr = ft_calloc(nmemb, size);
	i = 0;
	while (i < 40)
	{
		c = ptr[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	write(1, "new2", 4);

	free(ptr);
	i = 0;
	while (i < 40)
	{
		c = ptr[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	write(1, "new3", 4);

	ptr = calloc(nmemb, size);
	i = 0;
	while (i < 40)
	{
		c = ptr[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	write(1, "new4", 4);

	free(ptr);
	i = 0;
	while (i < 40)
	{
		c = ptr[i];
		write(1, &c, 1);
		i++;
	}
}*/