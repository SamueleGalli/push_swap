/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:15:42 by sgalli            #+#    #+#             */
/*   Updated: 2023/04/26 15:48:23 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra_check(t_list **s_a)
{
	t_list	*last;
	t_list	*tmp;

	last = *s_a;
	tmp = *s_a;
	if (last == NULL)
		return ;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *s_a;
	*s_a = last;
	tmp->next = NULL;
}

void	ft_rrb_check(t_list **s_b)
{
	t_list	*last;
	t_list	*tmp;

	last = *s_b;
	tmp = *s_b;
	if (last == NULL)
		return ;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *s_b;
	*s_b = last;
	tmp->next = NULL;
}

void	ft_rrr_check(t_list **s_a, t_list **s_b)
{
	ft_rra_check(s_a);
	ft_rrb_check(s_b);
}
