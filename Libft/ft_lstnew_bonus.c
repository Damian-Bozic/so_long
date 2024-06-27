/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:38:02 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/21 14:39:51 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*starting_node;

	starting_node = (t_list *)malloc(sizeof(t_list));
	if (!starting_node)
		return (NULL);
	starting_node->content = content;
	starting_node->next = (NULL);
	return (starting_node);
}

/*  int	main(void)
{
	int	i = 42;
	int	j;
	t_list *list = ft_lstnew(&i);

	if (!list)
		return (0);
	j = *(int *)(list->content);
	ft_putnbr_fd(j, 1);
	return (0);
}  */