/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:58:10 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/06 11:28:40 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (((char *)str)[i] != (char)c && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((void *)&(((char *)str)[i]));
}

/* int	main(void)
{
#include <string.h>
#include <stdio.h>
	int		c = -1;
	char	s[] = {0, 1, 2 ,3 ,4 ,5};
	char	*ptr;
	int		size = 7;

	ptr = ft_memchr(s, 2 + 256, 3);
	printf("%s", ptr);

	ptr = memchr(s, 2 + 256, 3);
	printf("\n%s", ptr);
} */