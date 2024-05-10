/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:19:07 by sgalli            #+#    #+#             */
/*   Updated: 2023/03/14 11:41:30 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int *(*f)(int *), void (*del)(int *))
{
	t_list	*node;
	t_list	*newlst;

	if (lst == 0)
	{
		return (lst);
	}
	newlst = NULL;
	while (lst != 0)
	{
		node = ft_lstnew(*f(&lst->content));
		if (node == 0)
		{
			ft_lstclear(&newlst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
