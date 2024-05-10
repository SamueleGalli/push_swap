/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:06:10 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/02 11:22:34 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*dichiaro le variabili
se la dimensione e = 3 eseguo ft_sort_three
se la dimensione e = 5 eseguo ft_sort_five
passo a a result sa e size_a e ci metto tutti gli elementi di sa
a arr passo result, size_a e i
*/

void	ft_lst_split(t_list **s_a, t_list **s_b, int size_a)
{
	if (size_a == 3)
	{
		ft_sort_three(s_a);
		return ;
	}
	if (size_a == 5)
	{
		ft_sort_five(s_a, s_b);
		return ;
	}
	sort_lis(s_a, s_b, size_a);
}

/*se ho dei numeri tra parentesi faccio il primo caso "1 2 3 4"
splitto per avere i numeri singoli in av
ottengo la size_a dello stack di numeri
altrimenti nel caso ce li abbia cosi (1 2 3 5)
vado nella funzione ft_write_lst*/
void	ft_check_avv(int c, char **v, t_list **s_a)
{
	int		size_a;
	char	**av;

	av = NULL;
	size_a = 0;
	if (c == 2)
	{
		av = ft_split(v[1], ' ');
		while (av[size_a] != NULL)
		{
			size_a++;
		}
		ft_write_lst(s_a, size_a, av, 0);
		size_a = -1;
		while (av[++size_a] != NULL)
			free(av[size_a]);
		free(av);
	}
	else if (c >= 3)
	{
		ft_write_lst(s_a, c, v, 1);
	}
}

/*creo le variabili e le inizzializzo
controllo se il numero di elementi e 2 senno da errore
prendo la lunghezza della lista e la metto in size_a
se la size_a e due gli ho gia swappati in ft_check_avv*/
int	main(int c, char **v)
{
	t_list	*s_a;
	t_list	*s_b;
	int		size_a;

	s_a = NULL;
	s_b = NULL;
	size_a = 0;
	if (c < 2 || v[1][0] == '\0')
		return (0);
	else
		ft_check_avv(c, v, &s_a);
	size_a = ft_lstsize(s_a);
	ft_lst_split(&s_a, &s_b, size_a);
	ft_lst_delete(&s_a);
	ft_lst_delete(&s_b);
}
