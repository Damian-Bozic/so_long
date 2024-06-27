/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:40:30 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/21 15:41:14 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	i = 0;
	current = lst;
	if (!lst)
		return (0);
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

/*  int	main(void)
{
	int	src1 = 42;
	int src2 = 21;
	int	j;
	t_list *main_list = ft_lstnew(&src1);

	if (!main_list)
		write(1, "malloc error", 12);
	ft_lstadd_front(&main_list, ft_lstnew(&src2));

	t_list *current = main_list;
	while (current)
	{
		j = *(int*)current->content;
		ft_putnbr_fd(j, 1);
		write(1, "\n", 1);
		current = current->next;
	}
	j = ft_lstsize(main_list);
	ft_putnbr_fd(j, 1);
	return (0);
}  */