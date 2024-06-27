/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:41:41 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/13 14:50:35 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	ft_toupper_mod(unsigned int index, char c)
{
	if (index % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
	}
	return (c);
}*/

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = ft_strdup(str);
	if (!rtn)
		return (0);
	while (str[i] != '\0')
	{
		rtn[i] = f(i, rtn[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

/*int	main(void)
{
#include "stdio.h"
	char	str[] = "how on earth?";
	char	*rtn;

	rtn = ft_strmapi(str, ft_toupper_mod);
	printf("%s", rtn);
}*/