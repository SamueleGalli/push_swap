/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:24:11 by sgalli            #+#    #+#             */
/*   Updated: 2023/04/20 11:39:27 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*scambia i primi 2 numeri
crea t e t2
supponiamo (5,7,9,11)
dovrebbe diventare (7,5,9,11)
t punta al primo elemento (5)
inziamo facendo puntare a t2 il successivo elemento (7)
lo stack parte da (7) ora (*s_a = t2;)
(t->next = t2->next) cio fa puntare t->next a 5->9
((t2)->next = t)
qua invece il succesivo elemento di t2 fa puntare a 7
cio porta questo 7->5   5->9
scrivo lo swap*/

void	ft_sa(t_list **s_a)
{
	t_list	*t;
	t_list	*t2;

	t = *s_a;
	t2 = t->next;
	*s_a = t2;
	t->next = t2->next;
	t2->next = t;
	write(1, "sa\n", 3);
	return ;
}

/*la stessa cosa di sa con b*/
void	ft_sb(t_list **s_b)
{
	t_list	*t;
	t_list	*t2;

	t = *s_b;
	t2 = t->next;
	*s_b = t2;
	t->next = t2->next;
	t2->next = t;
	write(1, "sb\n", 3);
	return ;
}

/*entrambe le cose sia a s_a e a s_b*/
void	ft_ss(t_list **s_a, t_list **s_b)
{
	t_list	*t;
	t_list	*t2;

	t = *s_a;
	t2 = t->next;
	*s_a = t2;
	t->next = t2->next;
	t2->next = t;
	t = NULL;
	t2 = NULL;
	t = *s_b;
	t2 = t->next;
	*s_b = t2;
	t->next = t2->next;
	t2->next = t;
	write(1, "ss\n", 3);
	return ;
}

/*sposta il primo elemento di b in  a
t e uguae al primo elemento di s_b
s_b = al successivo suo elemento
il successivo elemento di t->next diventa s_a
s_a e uguale a t*/
void	ft_pa(t_list **s_b, t_list **s_a)
{
	t_list	*t;

	if (*s_b == NULL)
	{
		return ;
	}
	t = *s_b;
	*s_b = (*s_b)->next;
	t->next = *s_a;
	*s_a = t;
	write(1, "pa\n", 3);
	return ;
}

/*controllo se lo s_a e nullo
sposta il primo elemento dello stack di a in b
salvo il primo elemento della lista in t
lo s_a punta al successivo lista dello stesso s_a
il successivo elemento della lista t->next punta allo s_b
associo allo s_b t e scrivo l'algoritmo
es (5 ,7 ,3 ,1 ,8)
s_a(7, 3, 1, 8)
s_b(5)
secondo ciclo
metto al primo elemento di s_b il successivo numero
swappando il precedente col nuovo
s_a(3, 1, 8)
s_b(7, 5)*/

void	ft_pb(t_list **s_a, t_list **s_b)
{
	t_list	*t;

	if (*s_a == NULL)
	{
		return ;
	}
	t = *s_a;
	*s_a = (*s_a)->next;
	t->next = *s_b;
	*s_b = t;
	write(1, "pb\n", 3);
	return ;
}
