/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:48:18 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/07 12:42:18 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src || !n)
		return (dest);
	if (src >= dest)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
		while (n-- > 0)
			((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
// no null termination

/* int	main(void)
{
#include <string.h>
#include <stdio.h>
	int		size = 8;
	int		readlen = 22;/
	char	src1[] = "abcdefghi";
	char	*dest1;
	char	src2[] = "abcdefghi";
	char	*dest2;
	
	dest1 = &src1[2];
	ft_memmove(dest1, src1, size);
	write(1, src1, readlen);
	write(1, "\n", 1);
	write(1, dest1, readlen);

	write(1, "\n", 1);

	dest2 = &src2[2];
	memmove(dest2, src2, size);
	write(1, src2, readlen);
	write(1, "\n", 1);
	write(1, dest2, readlen);
} */