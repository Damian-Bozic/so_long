/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:30:46 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/12 18:37:15 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intsize(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = intsize(n);
	str = malloc(i + 2);
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	str[i + 1] = '\0';
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		if (n < 0)
		{
			str[i] = (((n % 10) * -1) + '0');
		}
		else
			str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

/*int	main(void)
{
#include "stdio.h"
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(i);
	printf("%s", str);
	free(str);
}*/
