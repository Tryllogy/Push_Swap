/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufeal <madufeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:59:17 by madufeal          #+#    #+#             */
/*   Updated: 2026/01/30 20:44:01 by madufeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_reverse(char name, t_bench *bench)
{
	if (bench->to_print)
		ft_printf("rr%c\n", 1, name);
	if (name == 'a')
		(*bench).rra++;
	else
		(*bench).rrb++;
	(*bench).total++;
}

int	reverse(t_list **lst, t_bench *bench)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return (1);
	print_reverse((*lst)->name, bench);
	tmp = last_lst(*lst);
	tmp->prev->next = NULL;
	add_front_lst(lst, tmp);
	tmp->prev = NULL;
	*lst = first_lst(*lst);
	return (0);
}

void	d_reverse(t_list **a, t_list **b, t_bench *bench)
{
	int	tmp;

	tmp = bench->to_print;
	if (bench->to_print)
		ft_printf("rrr\n", 1);
	bench->to_print = 0;
	if (!reverse(a, bench))
	{
		(*bench).rra--;
		(*bench).total--;
	}
	if (!reverse(b, bench))
	{
		(*bench).rrb--;
		(*bench).total--;
	}
	(*bench).total++;
	(*bench).rrr++;
	bench->to_print = tmp;
}
