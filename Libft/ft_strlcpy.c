/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:30:01 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/06 17:34:23 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n - 1 && n != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (n != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

//if there is no free byte in dest do i not null terminate?

/*int	main(void)
{
	#include <bsd/string.h>
	// ^^^ Run with -lbsd flag
	#include <stdio.h>
	char dest1[] = "abcdfghijklmnopqrstuvwxyz";
	char dest2[] = "abcdfghijklmnopqrstuvwxyz";
	char src[] = "123456789idksome other stuff";
	size_t	len = 5;
	size_t	j;

	j = 0;
	j = ft_strlcpy(dest1, src, len);
	printf("%ld", ft_strlen(dest1));
	printf("\n%s", dest1);
	printf("\n%ld", j);

	j = 0;
	j = strlcpy(dest2, src, len);
	printf("\n%ld", ft_strlen(dest2));
	printf("\n%s", dest2);
	printf("\n%ld", j);
}*/