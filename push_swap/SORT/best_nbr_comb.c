/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_nbr_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:10:08 by sgalli            #+#    #+#             */
/*   Updated: 2023/04/27 15:44:33 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_best_nbr_a(t_list *s_a, int size_a, int *arr, int max)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (s_a != NULL)
	{
		i = 0;
		while (s_a->content != arr[i] && i < max)
		{
			if (i == max - 1)
			{
				return (pos);
			}
			i++;
		}
		s_a = s_a->next;
		pos++;
	}
	size_a = -1;
	return (size_a);
}

/*vedo l'elemento piu piccolo di temp e se ce prendo la posizione
e libero le variabili*/

int	ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size_b)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (i < size_b)
	{
		if (tmp[i] < tmp[pos])
			pos = i;
		i++;
	}
	free(arr_a);
	free(arr_b);
	free(tmp);
	return (pos);
}

/*allochi un array di int grande quanto size_b
entro ne ciclo
vedo se i numeri sono positivi o negativie nel caso sia uno di 
loro negativo lo rendo positivo
alla fine ottero un array con la loro somma perche cosi posso
sapre quale operazione fare
infine ritorno la posizione del piu piccolo
che indicare il calcolo
*/

int	ft_best_comb(int *arr_a, int *arr_b, int size_b)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *)malloc(sizeof(int) * size_b);
	if (tmp == 0 || arr_a == 0 || arr_b == 0)
	{
		ft_display_exit();
	}
	while (++i < size_b)
	{
		if ((arr_a[i] > 0 && arr_b[i] > 0)
			|| (arr_a[i] < 0 && arr_b[i] < 0))
			tmp[i] = ft_max_nbr(arr_a[i], arr_b[i]);
		else
		{
			if (arr_a[i] < 0)
				arr_a[i] *= -1;
			if (arr_b[i] < 0)
				arr_b[i] *= -1;
			tmp[i] = arr_a[i] + arr_b[i];
		}
	}
	return (ft_best_comb_helper(arr_a, arr_b, tmp, size_b));
}

/*ordino numero*/
int	ft_move_a(int a, int b, t_list **s_a, t_list **s_b)
{
	while (a < 0 && b < 0)
	{
		ft_rrr(s_a, s_b);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		ft_rr(s_a, s_b);
		a--;
		b--;
	}
	if (a < 0)
	{
		while (a++ < 0)
			ft_rra(s_a);
	}
	else if (a > 0)
	{
		while (a-- > 0)
			ft_ra(s_a);
	}
	return (b);
}

/*inizzializzo le variabili e metto s_b in t_b
alloco con malloc due arrai delle dimensioni calcolate prima
altimenti entro nel while e e alloco alla iesima posizione
un numero che indichera l'operazione da fare
prima in b
poi in a
metto in in due variabili in int arr_b e arr_a
calcolo la loro somma per avere l'operazione ottimale da fare
*/
int	ft_best_nbr_b(t_list **s_b, int size_b, t_list **s_a, int size_a)
{
	int		*arr_b;
	int		*arr_a;
	t_list	*t_b;
	int		i;

	i = -1;
	t_b = *s_b;
	arr_a = (int *)malloc(sizeof(int) * size_b);
	arr_b = (int *)malloc(sizeof(int) * size_b);
	while (++i < size_b)
		arr_b[i] = is_max(i, size_b);
	i = -1;
	while (++i < size_b && t_b != NULL)
	{
		arr_a[i] = ft_the_needed_a(*s_a, t_b->content, size_a);
		t_b = t_b->next;
	}
	i = ft_best_comb(ft_intcopy(arr_a, size_b),
			ft_intcopy(arr_b, size_b), size_b);
	i = ft_move_a(arr_a[i], arr_b[i], s_a, s_b);
	free(arr_a);
	free(arr_b);
	return (i);
}
