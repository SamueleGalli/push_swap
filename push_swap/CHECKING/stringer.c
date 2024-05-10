/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:37:30 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/02 11:36:32 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	string_lis(char *s)
{
	int			i;

	i = 0;
	if (s[0] == '\0')
		ft_display_exit();
	if ((s[0] == '+' || s[0] == '-') \
	&& (s[1] > '0' && s[1] <= '9'))
		i++;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			ft_display_exit();
	}
	attttoi(s);
}

void	string_char(char *s, char **av)
{
	int			i;
	int			k;

	i = 0;
	k = -1;
	if (s[0] == '\0')
		ft_display_exit();
	if ((s[0] == '+' || s[0] == '-') \
	&& (s[1] > '0' && s[1] <= '9'))
		i++;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
		{
			while (av[++k] != NULL)
				free(av[k]);
			free(av);
			ft_display_exit();
		}
	}
	atttoi(s, av);
}
/*prendo il valore del numero piu piccolo possibile*/

int	more_low(t_list *p_a)
{
	int		value;
	t_list	*p_a2;

	p_a2 = p_a;
	value = 2147483647;
	while (p_a2 != NULL)
	{
		if (p_a2->content < value)
		{
			value = p_a2->content;
		}
		p_a2 = p_a2->next;
	}
	return (value);
}

/*vedo se l'elemento di a a cui mi sono fermato
e piu grande di quello di b
se il contenuto a cui mi sono fermato e piu piccolo o uguale
a p2 prendo la posizione del piu piccolo
aggiornandolo in caso di ancora piu piccolo
ciclo p
ritorno i2 che e la posizione del piu piccolo*/

int	find_i(t_list *p, t_list *p2, int i, int b_cont)
{
	int	i2;

	i2 = i;
	p2 = p;
	while (p != NULL)
	{
		if (p->content > b_cont && p->content <= p2->content)
		{
			i2 = i;
			p2 = p;
		}
		i++;
		p = p->next;
	}
	return (i2);
}

/*cerco il numero piu piccolo possibile
lo calcolo in more_low
ciclo il puntatore di a fino alla fine
vedo se il numero di p_a = a low_num
qundi al piu piccolo e nel caso prendo la posizione del piu piccolo
alla fine ritorno il piu piccolo*/

int	low_num(t_list *s_a, int size_a, int i2)
{
	int		i;
	t_list	*p_a;
	int		low_num;

	i = 0;
	p_a = s_a;
	low_num = more_low(p_a);
	p_a = s_a;
	while (p_a != NULL && i < size_a)
	{
		if (p_a->content == low_num)
		{
			i2 = i;
		}
		i++;
		p_a = p_a->next;
	}
	return (i2);
}
