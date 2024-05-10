/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:50:42 by sgalli            #+#    #+#             */
/*   Updated: 2023/04/27 15:15:58 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*finlish(t_s s, int len, int i, int *lenght)
{
	s.lis = malloc(sizeof(int) * len);
	i = len - 1;
	while (i >= 0)
	{
		s.lis[i] = s.arr[s.pos];
		s.pos = s.prev[s.pos];
		i--;
	}
	*lenght = len;
	free(s.cont);
	free(s.prev);
	return (s.lis);
}

int	whiler(int j, int i, t_s *s)
{
	while (j < i)
	{
		if (s->arr[j] < s->arr[i] && s->cont[j] + 1 >= s->cont[i])
		{
			s->cont[i] = s->cont[j] + 1;
			s->prev[i] = j;
		}
		j++;
	}
	return (j);
}

int	looping(t_s *s, int i, int j, int size_a)
{
	int	r;

	r = 1;
	while (i < size_a)
	{
		s->cont[i] = 1;
		s->prev[i] = -1;
		j = 0;
		j = whiler (j, i, s);
		if (r < s->cont[i])
		{
			r = s->cont[i];
			s->pos = i;
		}
		i++;
	}
	return (r);
}
