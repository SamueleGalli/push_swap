/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:02:42 by sgalli            #+#    #+#             */
/*   Updated: 2023/04/26 12:26:40 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_min_nbr(int a, int b)
{
	int	a1;
	int	b1;

	a1 = a;
	b1 = b;
	if (a < 0)
	{
		a *= -1;
	}
	if (b < 0)
	{
		b *= -1;
	}
	if (a == b)
	{
		return (a1);
	}
	if (a < b)
	{
		return (a1);
	}
	else
	{
		return (b1);
	}
}
/*in caso negativo cambio il segno e poi ritorno il piu grande*/

int	ft_max_nbr(int a, int b)
{
	if (a < 0)
	{
		a *= -1;
	}
	if (b < 0)
	{
		b *= -1;
	}
	if (b > a)
	{
		return (b);
	}
	else
	{
		return (a);
	}
}

/*prendo posizione e valore dell'elemento piu piccolo
vedo dove si trova con is_max
eseguo l'operazione di ordinamento
*/
void	ft_search_min(t_list **s_a, int size_a)
{
	int		pos;
	int		pos_min;
	int		min;
	t_list	*tmp;

	pos = 0;
	pos_min = 0;
	tmp = *s_a;
	min = tmp->content;
	while (pos < size_a)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			pos_min = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	tmp = NULL;
	pos = is_max(pos_min, size_a);
	ft_move_a(pos, 0, s_a, &tmp);
}
