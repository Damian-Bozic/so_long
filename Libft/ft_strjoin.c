/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:38:48 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/07 12:20:13 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t		i;
	size_t		j;
	char		*rtn;

	i = 0;
	j = 0;
	rtn = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!rtn)
		return (0);
	while (i < ft_strlen(str1))
	{
		rtn[i] = str1[i];
		i++;
	}
	while (j < ft_strlen(str2))
	{
		rtn[i + j] = str2[j];
		j++;
	}
	rtn[i + j] = '\0';
	return (rtn);
}
//what is the difference between returning NULL, '\0', and 0?

/*int	main(void)
{
	#include <stdio.h>
	char	str1[6] = "start\0";
	char	str2[6] = " end.\0";
	char	*ptr;

	ptr = ft_strjoin(str1, str2);
	printf("%s", ptr);
	free(ptr);
	printf("\n%s", ptr);
}*/
