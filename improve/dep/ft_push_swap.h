/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:03:06 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/02 17:57:39 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct t_ps_moves
{
	int 				(*move)(int **stacks, int stack, int *end, int mod);
	int					**stacks;
	int					stack;
	int					*end;
	int					mod;
	struct t_ps_moves	*next;
	struct t_ps_moves	*prev;

}						t_ps_moves;

// RADIX ALGORYTHM
int (*ft_radix_algorythm(int **stacks, int *stack, int *end)) (int **, int, int *, int);
void	ft_radix_pslst(t_ps_moves **lst);
// PAIR ALGORYTHM
void ft_get_pair(void);
t_ps_moves	*ft_pair_attach(t_ps_moves *node, int *nb_a, int *nb_b);
t_ps_moves **ft_pair_next(int **stacks, int *end, int *nb_a, int *nb_b);
void	ft_pair_algorythm(int **stacks, int *end);
// UTILS
int	*ft_arrcpy(int *src, int size);
int **ft_arr2cpy(int **src, int y, int x);
unsigned int	ft_itou(int nb);
//STRCT AND MODULES
t_ps_moves	*ft_dblstlast(t_ps_moves *lst);
int	ft_next_node(t_ps_moves **lst, int (*move)(int **, int, int *, int), int stack);
void	ft_dblstaddlst(t_ps_moves **lst_a, t_ps_moves **lst_b);
t_ps_moves	*ft_new_node(int **stacks, int *end);
//PARSING
int	ft_str_count(char *argv);
int	ft_check_duplicity(int *numbers);
int	ft_check_isalldigit(int argc, char **argv);
int	*ft_get_numbers(int argc, int count, char **argv);
void	ft_normalize(int **stacks, int *end);
//MOVES
int	ft_swap(int **stacks, int stack, int *end, int mod);
int	ft_push(int **stacks, int stack, int *end, int mod);
int	ft_rotate(int **stacks, int stack, int *end, int mod);
int	ft_rev_rotate(int **stacks, int stack, int *end, int mod);

#endif