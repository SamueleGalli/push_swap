/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:38:18 by sgalli            #+#    #+#             */
/*   Updated: 2023/04/20 11:38:29 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* esempio (1, 3, 2)
sposta il primo elemento in ultima posizione
prima di tutto controllo se lo stack e nullo
poi assegno a last e first il primo elemento dell s_a
arrivo all'ultimo elemento di last
faccio puntare lo s_a al successivo elemento di first next(1)
first next diventa null
e al posto dell'ultimo elemento ci metto il primo
e scrivo l'algoritmo usato
(3 ,2, 1)*/
void	ft_ra(t_list **s_a)
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
	write(1, "ra\n", 3);
	return ;
}

/*se uno e null ritorno
esempio (1 3 2)
il puntatore al primo lo faccio punatare al secondo
il suo successivo diventa null
e il precedente a fisrt diventa last->next
stessa cosa sopra ma con s_b
(3 2 1)*/
void	ft_rb(t_list **s_b)
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
	write(1, "rb\n", 3);
	return ;
}

/* e ra e rb insieme*/
void	ft_rr(t_list **s_a, t_list **s_b)
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
	write(1, "rr\n", 3);
	return ;
}
