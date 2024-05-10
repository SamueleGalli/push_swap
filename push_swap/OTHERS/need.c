/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:15:26 by sgalli            #+#    #+#             */
/*   Updated: 2023/04/26 12:06:37 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*se max e maggiore di size tolgo a max la size
perche e il piu grande
calcolo e ritorno max che indica l'operazione da fare*/
int	is_max(int max, int size)
{
	if (max > (size / 2))
		max = max - size;
	return (max);
}

/*creo due puntatori che puntano entrambi a s_a
inizializzo le i
ciclo finche gli elementi di a sono minori dell'elemento elemento
di b
se arrivo alla fine mi prendo la posizione del piu piccolo
altrimenti trovo il piu piccolo dopo il piu grande trovato
ritorno con max il valore piu corretto da ritornare in base
se si trova nella prima parte della stringa o dopo
quindi dopo valori negativi prima positivi*/
int	ft_the_needed_a(t_list *s_a, int cont_b, int size_a)
{
	int		i;
	int		i2;
	int		peak;
	t_list	*pa;
	t_list	*pa2;

	pa = s_a;
	pa2 = s_a;
	i = 0;
	peak = 0;
	while ((pa != NULL) && (pa->content < cont_b))
	{
		i++;
		pa = pa->next;
		pa2 = pa2->next;
	}
	if (pa == NULL)
		peak = low_num(s_a, size_a, peak);
	if (pa != NULL)
		peak = find_i(pa, pa2, i, cont_b);
	i2 = is_max(peak, size_a);
	return (i2);
}

/*alloco copy con size o di a o di b
se da errore esco
mentre i < della dimensione della size
copio in copy arr e ci metto il carattere nullo
ritorno copy*/
int	*ft_intcopy(int *arr, int size_b)
{
	int	i;
	int	*copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * size_b);
	if (arr == 0 || copy == 0)
		ft_display_exit();
	while (i < size_b)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}
