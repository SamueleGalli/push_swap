/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:01:28 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/02 11:38:41 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*lis(int size_a, t_s s, int *len)
{
	int	i;
	int	k;
	int	size;
	int	l;

	s.cont = malloc(sizeof(int) * size_a);
	s.prev = malloc(sizeof(int) * size_a);
	i = 0;
	k = 0;
	l = 0;
	size = looping(&s, k, l, size_a);
	return (finlish(s, size, i, len));
}

int	*arrayter(t_list *s_a, int size_a)
{
	int	i;
	int	*sa;

	i = 0;
	sa = malloc(sizeof(int) * size_a);
	while (i != size_a)
	{
		sa[i] = s_a->content;
		i++;
		s_a = s_a->next;
	}
	return (sa);
}

void	shortcut(t_s s, t_list **s_a, int size_a, t_list **s_b)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (len++ < size_a)
	{
		if (i < s.len && s.p->content == s.lis[i])
		{
			s.p = s.p ->next;
			ft_ra(s_a);
			i++;
		}
		else
		{
			s.p = s.p->next;
			ft_pb(s_a, s_b);
		}
	}
}

/*creo un array con la lista convertita
inizzialisso le variabili
eseguo lis
calcolo operazioene ottimale e la eseguo
controllo l'operazione da fare per gli elementi piu piccoli da fare*/
void	sort_lis(t_list **s_a, t_list **s_b, int size_a)
{
	t_s	s;

	s.p = *s_a;
	s.arr = arrayter(*s_a, size_a);
	s.lis = lis(size_a, s, &s.len);
	shortcut(s, s_a, size_a, s_b);
	free(s.arr);
	free(s.lis);
	ft_move_to_a(s_a, s_b);
	ft_search_min(s_a, size_a);
}

void	atttoi(char *s, char **av)
{
	long long	j;
	int			i;

	i = 0;
	j = ft_atoi(s);
	if (j >= 2147483647 || j <= -2147483648)
	{
		while (av[i] != NULL)
		{
			free(av[i]);
			i++;
		}
		free(av);
		ft_display_exit();
	}
	return ;
}
