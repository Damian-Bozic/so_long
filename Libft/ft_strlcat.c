/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:48:32 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/07 17:50:47 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	rtn;

	i = ft_strlen(dest);
	rtn = i + ft_strlen(src);
	if (n < i)
		return (n + ft_strlen(src));
	ft_strlcpy(&dest[i], src, n - i);
	return (rtn);
}
// Not perfect replica, needs more testing
/*int	main(void)
{
	#include <bsd/string.h>
	#include <stdio.h>
// Run with -lbsd flag

	int		n = 8;
	char	buffer1[10] = "123456";
	char	buffer2[10] = "123456";
	char	last[] = "789";

	ft_putnbr_fd(ft_strlcat(buffer1, last, n), 1);
	write(1, "\n", 1);
	ft_putstr_fd(buffer1, 1);

	write(1, "\n,", 1);
	ft_putnbr_fd(strlcat(buffer2, last, n), 1);
	write(1, "\n,", 1);
	ft_putstr_fd(buffer2, 1);
}*/