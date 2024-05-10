/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:57:05 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/04 10:31:49 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lst_delete(t_list **stack)
{
	t_list	*t;

	if (*stack == NULL)
	{
		return ;
	}
	t = *stack;
	while (*stack != NULL)
	{
		t = (*stack)->next;
		free(*stack);
		*stack = t;
	}
}

/*controllo se il numero passatogli e uguale a check
nel caso ciclo e vedo il succesivo
mi fermo prima di se stesso col while
nel caso do errore e esco*/
void	ft_lstcheck(t_list **s_a, int check, char **av, int j)
{
	t_list	*a;	
	int		i;

	a = *s_a;
	i = 0;
	while (a->next != NULL)
	{
		if (a->content == check)
		{
			if (av[i] != NULL && j == 0)
			{
				while (av[i] != NULL)
				{
					free(av[i]);
					i++;
				}
				free(av);
			}
			ft_lst_delete(s_a);
			ft_display_exit();
		}
		a = a->next;
	}
	return ;
}

/*identico a ft_lst_order ma con il controllo se il primo e piu piccolo
nel caso e piu piccolo esco perche e giusto
altrimenti eseguo la funzione per ordinare ft_sa(s_a);*/
void	ft_lst_inverted(t_list **s_a, int j, char **av)
{
	t_list	*t;
	t_list	*t2;
	int		i;
	int		k;

	i = j;
	k = 0;
	t = *s_a;
	t2 = t->next;
	while (t2 != NULL)
	{
		if (t->content < t2->content)
		{
			return ;
		}
		t = t->next;
		t2 = t2->next;
		k++;
	}
	freear(k, av, s_a, i);
}

/*dichiaro t e t2
t = allo stack pieno di numeri
t2 al successivo elemento dello stack
se l'elemeto dello stack_a e maggiore del succiessivo esci dalla funzione
altrimenti alla fine esce dal programma perche e gia ordinato*/

void	ft_lst_order(t_list **s_a, char **av, int j)
{
	t_list	*t;
	t_list	*t2;
	int		size_a;

	t = *s_a;
	size_a = -1;
	t2 = t->next;
	while (t2 != NULL)
	{
		if (t->content > t2->content)
		{
			ft_lst_inverted(s_a, j, av);
			return ;
		}
		t = t->next;
		t2 = t2->next;
	}
	if (j == 0)
	{
		while (av[++size_a] != NULL)
			free(av[size_a]);
		free(av);
	}
	ft_lst_delete(s_a);
	exit(0);
}

/*converto la stringa in numero
lo aggiungo nella lista t
all'ultimo elemento della lista (s_a)ci metto t
controllo se il numero e valido per ogni numero
*/
void	ft_write_lst(t_list **s_a, int size_a, char **av, int i)
{
	t_list	*t;
	int		j;

	t = NULL;
	j = i;
	if (i == 1)
	{
		while (av[i] != NULL)
			string_lis(av[i++]);
	}
	else
	{
		while (av[i] != NULL)
			string_char(av[i++], av);
	}
	i = j;
	while (i < size_a)
	{
		t = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(s_a, t);
		ft_lstcheck(s_a, t->content, av, j);
		i++;
	}
	ft_lst_order(s_a, av, j);
	t = NULL;
}
