/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:40:25 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/13 17:40:51 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printint(char c, int fd)
{
	c = c + '0';
	write(fd, &c, 1);
}

static void	printfiltered(int nbr, int fd)
{
	int		i;
	int		j;
	char	str[10];

	i = 9;
	while (nbr != 0)
	{
		j = nbr % 10;
		nbr = nbr / 10;
		str[i] = j;
		i--;
	}
	i++;
	while (i < 10)
	{
		printint(str[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	printfiltered(n, fd);
}

/*int	main(void)
{
	int	i;

	i = -5;
	ft_putnbr_fd(i, 2);
}*/