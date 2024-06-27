/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:16:31 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/13 16:18:50 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	ft_toupper_mod(unsigned int index, char *c)
{
	if (index % 2 == 0)
	{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
	}
}*/

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		f(i, &str[i]);
		i++;
	}
}

/*int	main(void)
{
#include "stdio.h"
	char	str[] = "pointers";

	ft_striteri(str, ft_toupper_mod);
	printf("%s", str);
}*/