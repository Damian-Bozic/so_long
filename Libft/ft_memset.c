/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:54:11 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/04 12:41:34 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int	i;

	i = 0;
	while (n-- > 0)
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
#include <string.h>
#include <stdio.h>
	int		size;
	char	c;
	char	str[] = "If I had to guess this should work.";
	char	*ptr;

	c = '$';
	size = 6;
	ptr = ft_memset(str, c, size);
	printf("%s", ptr);

	c = '$';
	size = 6;
	ptr = memset(str, c, size);
	printf("\n%s", ptr);

}*/
