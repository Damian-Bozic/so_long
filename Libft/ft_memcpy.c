/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:13:10 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/04 12:47:59 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	while (n-- > 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
#include <string.h>
#include <stdio.h>
	int		size;
	char	src[] = "If I had to guess this should work.";
	char	dest1[] = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
	char	dest2[] = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";

	size = 12;
	ft_memcpy(dest1 + 2, src, size);
	printf("%s", dest1);

	memcpy(dest2 + 2, src, size);
	printf("\n%s", dest2);
}*/