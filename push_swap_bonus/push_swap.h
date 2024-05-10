/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:08:05 by sgalli            #+#    #+#             */
/*   Updated: 2023/05/04 10:51:15 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_s
{
	int		*arr;
	int		*lis;
	t_list	*p;
	int		i;
	int		len;
	int		*cont;
	int		*prev;
	int		pos;
}	t_s;

void	attttoi(char *s);
void	cont_check(t_list **s_a, t_list **s_b, char *s);
void	check(t_list **s_a, t_list **s_b, char *s);
void	final_check(t_list *s_a);
void	ft_lst_split(t_list **s_a, t_list **s_b, int size_a);
void	ft_write_lst(t_list **s_a, int c, char **v, int i);
void	ft_lst_order(t_list **s_a, char **av, int j);
void	ft_lst_inverted(t_list **s_a, int j, char **av);
void	ft_lst_delete(t_list **stack);
void	freear(int k, char **av, t_list **s_a, int i);
void	ft_sa(t_list **s_a);
void	ft_sb(t_list **s_b);
void	ft_ss(t_list **s_a, t_list **s_b);
void	ft_pa(t_list **s_b, t_list **s_a);
void	ft_pb(t_list **s_a, t_list **s_b);
void	ft_ra(t_list **s_a);
void	ft_rb(t_list **s_b);
void	ft_rr(t_list **s_a, t_list **s_b);
void	ft_rra(t_list **s_a);
void	ft_rrb(t_list **s_b);
void	ft_rrr(t_list **s_a, t_list **s_b);
void	ft_sort_three(t_list **s_a);
void	ft_sort_five(t_list **s_a, t_list **s_b);
void	sort_lis(t_list **s_a, t_list **s_b, int size_a);
void	atttoi(char *s, char **av);
void	string_char(char *s, char **av);
void	ft_search_min(t_list **s_a, int size);
void	ft_move_to_a(t_list **s_a, t_list **s_b);
void	ft_check_sort(t_list *s_a);
void	string_lis(char *s);
void	ft_sa_check(t_list **s_a);
void	ft_sb_check(t_list **s_b);
void	ft_check_avv(int c, char **v, t_list **s_a);
void	ft_pa_check(t_list **s_b, t_list **s_a);
void	ft_rb_check(t_list **s_b);
void	ft_rr_check(t_list **s_a, t_list **s_b);
void	ft_ss_check(t_list **s_a, t_list **s_b);
void	ft_ra_check(t_list **s_a);
void	ft_pb_check(t_list **s_a, t_list **s_b);
void	ft_rrr_check(t_list **s_a, t_list **s_b);
void	ft_rrb_check(t_list **s_b);
void	ft_lstcheck(t_list **s_a, int check, char **av, int j);
void	ft_rra_check(t_list **s_a);

int		ft_best_nbr_b(t_list **s_b, int size_b,
			t_list **s_a, int size_a);
int		*finlish(t_s s, int len, int i, int *lenght);
int		whiler(int j, int i, t_s *s);
int		looping(t_s *s, int i, int j, int size_a);
int		ft_best_nbr_a(t_list *s_a, int size_a, int *arr, int max);
int		ft_best_comb(int *arr_a, int *arr_b, int size_b);
int		ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size_b);
int		ft_move_a(int a, int b, t_list **s_a, t_list **s_b);
int		low_num(t_list *s_a, int size_a, int i2);
int		find_i(t_list *p, t_list *p2, int i, int b_cont);
int		more_low(t_list *p_a);
int		*ft_intcopy(int *arr, int size_b);
int		ft_the_needed_a(t_list *s_a, int cont, int size_a);
int		is_max(int max, int size);
int		ft_min_nbr(int a, int b);
int		ft_max_nbr(int a, int b);

#endif
