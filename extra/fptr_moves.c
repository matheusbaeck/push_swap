/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fptr_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:28:55 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/04/29 01:12:21 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_pa(int **stacks, int *end, int mod);
{
	ft_push(stacks, 0, end, mod);
}

void	ft_pb(int **stacks, int *end, int mod);
{
	ft_push(stacks, 1, end, mod);
}

void	ft_ra(int **stacks, int *end, int mod);
{
	ft_rotate(stacks, 0, end, mod);
}

void	ft_rb(int **stacks, int *end, int mod);
{
	ft_rotate(stacks, 1, end, mod);
}

void	ft_rr(int **stacks, int *end, int mod);
{
	ft_rotate(stacks, 1, end, 2);
}

void	ft_rra(int **stacks, int *end, int mod);
{
	ft_rev_rotate(stacks, 0, end, mod);
}

void	ft_rrb(int **stacks, int *end, int mod);
{
	ft_rev_rotate(stacks, 1, end, mod);
}

void	ft_rrb(int **stacks, int *end, int mod);
{
	ft_rev_rotate(stacks, 1, end, 2);
}