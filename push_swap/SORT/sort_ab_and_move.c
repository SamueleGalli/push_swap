/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ab_and_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:10:46 by sgalli            #+#    #+#             */
/*   Updated: 2023/04/20 11:39:25 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*inizializzo le variabili
entro nel ciclo
se i numeri non sono in ordine entro nel while
in un caso ipotetico tipo (3 1 2)
assegno a i(3)
assegno a j(1)
assegno a x(2) 
questo viene eseguito se i primi 2 numeri non sono ordinati e cambia i primi due
(ft_sa)
sposta il primo elemento in ultima posizione (ft_ra)
sposto l'ultimo elemento in prima posizione (ft_rra)*/
void	ft_sort_three(t_list **s_a)
{
	int		i;
	int		j;
	int		x;
	t_list	*tmp;

	j = 0;
	i = 0;
	x = 0;
	while ((i < j && j < x && x > i) == 0)
	{
		tmp = *s_a;
		i = tmp->content;
		tmp = tmp->next;
		j = tmp->content;
		tmp = tmp->next;
		x = tmp->content;
		if ((i > j && j < x && x > i) \
			|| (i > j && j > x && x < i) || (i < j && j > x && x > i))
			ft_sa(s_a);
		if (i > j && j < x && x < i)
			ft_ra(s_a);
		if (i < j && j > x && x < i)
			ft_rra(s_a);
	}
}

void	ordered(t_list **s_a)
{
	t_list	*p;
	t_list	*p2;

	p = *s_a;
	p2 = (*s_a)->next;
	while (p2 != NULL)
	{
		if (p->content > p2->content)
			return ;
		p = p->next;
		p2 = p2->next;
	}
	ft_lst_delete(s_a);
	exit(0);
}

/*eseguo il ciclo due volte
(5 ,7 ,3 ,1 ,8)
(ft_pa) 2 volte risultato
s_a(3, 1, 8)
s_b(7, 5)
ordino i  tre numeri di s_a
eseguo operazioni di ordinamento
eseguo operazioni di ordinamento finali per i valori piu piccoli*/
void	ft_sort_five(t_list **s_a, t_list **s_b)
{
	int	i;

	i = 2;
	while (i > 0)
	{
		ft_pb(s_a, s_b);
		i--;
	}
	ft_sort_three(s_a);
	ft_move_to_a(s_a, s_b);
	ft_search_min(s_a, ft_lstsize(*s_a));
}

/*prendo la dimensione del size_a e size_b
fino a che lo s_b e diverso da NULL
calcolato l'operazione la faccio 
passando da uno di questi if
se necessario
restituisco ad a il primo elemento di b
aumentando dimensione a e riducendo dimensione b
*/
void	ft_move_to_a(t_list **s_a, t_list **s_b)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_lstsize(*s_a);
	size_b = ft_lstsize(*s_b);
	while (*s_b != NULL)
	{
		i = ft_best_nbr_b(s_b, size_b, s_a, size_a);
		if (i < 0)
		{
			while (i++ < 0)
				ft_rrb(s_b);
		}
		else if (i > 0)
		{
			while (i-- > 0)
				ft_rb(s_b);
		}
		ft_pa(s_b, s_a);
		size_a = size_a + 1;
		size_b = size_b - 1;
	}
}
