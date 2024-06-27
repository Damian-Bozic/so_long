/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:22:08 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/06 14:38:35 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t n)
{
	size_t		len;
	char		*rtn;

	if (!str)
		return (0);
	if (ft_strlen(str) <= start)
	{
		rtn = ft_strdup("");
		return (rtn);
	}
	len = ft_strlen(str + start);
	if (len > n)
		len = n;
	rtn = malloc(len + 1);
	if (!rtn)
		return (0);
	ft_strlcpy(rtn, str + start, len + 1);
	return (rtn);
}

/*  int	main(void)
{
	#include <stdio.h>
	char	*ptr;
	char	str[] = "123321";

	printf ("%s", str);
	ptr = ft_substr(str, 2, 3);
	printf ("\n%s", ptr);
	free(ptr);
} */