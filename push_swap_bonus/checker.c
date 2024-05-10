/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:31:40 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/04 11:33:49 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_check(t_list *s_a)
{
	t_list	*p;

	p = s_a;
	if (s_a == NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (p->next != NULL)
	{
		if (p->content > p->next->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		p = p->next;
	}
	write(1, "OK\n", 3);
	return ;
}

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

void	cont_check(t_list **s_a, t_list **s_b, char *s)
{
	if (ft_strcmp(s, "rra\n") == 0)
		ft_rra_check(s_a);
	else if (ft_strcmp(s, "rrb\n") == 0)
		ft_rrb_check(s_b);
	else if (ft_strcmp(s, "rrr\n") == 0)
		ft_rrr_check(s_a, s_b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_lst_delete(s_a);
		ft_lst_delete(s_b);
		free(s);
		exit(0);
	}
}

void	check(t_list **s_a, t_list **s_b, char *s)
{
	while (s != NULL)
	{
		if (ft_strcmp(s, "sa\n") == 0)
			ft_sa_check(s_a);
		else if (ft_strcmp(s, "sb\n") == 0)
			ft_sb_check(s_a);
		else if (ft_strcmp(s, "ss\n") == 0)
			ft_ss_check(s_a, s_b);
		else if (ft_strcmp(s, "pa\n") == 0)
			ft_pa_check(s_b, s_a);
		else if (ft_strcmp(s, "pb\n") == 0)
			ft_pb_check(s_a, s_b);
		else if (ft_strcmp(s, "ra\n") == 0)
			ft_ra_check(s_a);
		else if (ft_strcmp(s, "rb\n") == 0)
			ft_rb_check(s_b);
		else if (ft_strcmp(s, "rr\n") == 0)
			ft_rr_check(s_a, s_b);
		else
			cont_check(s_a, s_b, s);
		free(s);
		s = ft_get_next_line_gnl(0);
	}
}

int	main(int c, char **v)
{
	t_list	*s_a;
	t_list	*s_b;
	char	*s;

	s_a = NULL;
	s_b = NULL;
	if (c < 2)
		return (0);
	else if (v[1][0] == '\0')
		return (0);
	else
		ft_check_avv(c, v, &s_a);
	s = ft_get_next_line_gnl(0);
	check(&s_a, &s_b, s);
	final_check(s_a);
	ft_lst_delete(&s_a);
	ft_lst_delete(&s_b);
}
