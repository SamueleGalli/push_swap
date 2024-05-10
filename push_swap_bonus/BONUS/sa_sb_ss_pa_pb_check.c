/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:57:18 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/04 11:43:39 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa_check(t_list **s_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *s_a;
	tmp2 = tmp->next;
	*s_a = tmp2;
	if (s_a == NULL || tmp->next == NULL || tmp2->next == NULL)
		return ;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	ft_sb_check(t_list **s_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *s_b;
	tmp2 = tmp->next;
	*s_b = tmp2;
	if (s_b == NULL || tmp->next == NULL || tmp2->next == NULL)
		return ;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	ft_ss_check(t_list **s_a, t_list **s_b)
{
	t_list	*ta;
	t_list	*tb;

	tb = *s_b;
	ta = *s_a;
	if (tb == NULL || ta == NULL || tb->next == NULL \
	|| ta->next == NULL)
		return ;
	ft_sa_check(s_a);
	ft_sb_check(s_b);
}

void	ft_pa_check(t_list **s_b, t_list **s_a)
{
	t_list	*tmp;

	if (*s_b == NULL)
	{
		return ;
	}
	tmp = *s_b;
	*s_b = (*s_b)->next;
	tmp->next = *s_a;
	*s_a = tmp;
	return ;
}

void	ft_pb_check(t_list **s_a, t_list **s_b)
{
	t_list	*tmp;

	if (*s_a == NULL)
	{
		return ;
	}
	tmp = *s_a;
	*s_a = (*s_a)->next;
	tmp->next = *s_b;
	*s_b = tmp;
	return ;
}
