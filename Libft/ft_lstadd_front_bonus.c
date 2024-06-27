/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:22:55 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/21 16:23:42 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
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
	return (0);
}  */