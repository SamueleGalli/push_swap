/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:23:47 by sgalli            #+#    #+#             */
/*   Updated: 2023/04/20 11:38:17 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*crea due liste last e first
vedo se lo s_a 0 s_a->next e nullo
last e first diventano il primo elemento di s_a
last arriva ll'ultimo elemento
*/
void	ft_ra_check(t_list **s_a)
{
	t_list	*last;
	t_list	*first;

	if (*s_a == NULL || (*s_a)->next == NULL)
	{
		return ;
	}
	last = *s_a;
	first = *s_a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*s_a = first->next;
	first->next = NULL;
	last->next = first;
	return ;
}

void	ft_rb_check(t_list **s_b)
{
	t_list	*last;
	t_list	*first;

	if (*s_b == NULL || (*s_b)->next == NULL)
	{
		return ;
	}
	last = *s_b;
	first = *s_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*s_b = first->next;
	first->next = NULL;
	last->next = first;
	return ;
}

void	ft_rr_check(t_list **s_a, t_list **s_b)
{
	t_list	*last;
	t_list	*first;

	if (*s_a == NULL || (*s_a)->next == NULL)
		return ;
	last = *s_a;
	first = *s_a;
	while (last->next != NULL)
		last = last->next;
	*s_a = first->next;
	first->next = NULL;
	last->next = first;
	if (*s_b == NULL || (*s_b)->next == NULL)
		return ;
	last = *s_b;
	first = *s_b;
	while (last->next != NULL)
		last = last->next;
	*s_b = first->next;
	first->next = NULL;
	last->next = first;
	return ;
}
