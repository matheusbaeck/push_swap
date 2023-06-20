/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:03:06 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/06/19 20:04:38 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//PARSING
int		ft_str_count(char *argv);
int		ft_check_duplicity(int *numbers);
int		ft_check_isalldigit(int argc, char **argv);
int		*ft_get_numbers(int argc, int size, char **argv);
void	ft_normalize(int **stacks, int *end);
//MOVES
int		ft_swap(int **stacks, int stack, int *end, int mod);
int		ft_push(int **stacks, int stack, int *end, int mod);
int		ft_rotate(int **stacks, int stack, int *end, int mod);
int		ft_rev_rotate(int **stacks, int stack, int *end, int mod);
//ALGORYTHM LOWER
void	ft_algorythm_3n(int **stacks, int stack, int *end);
void	ft_algorythm_5n(int **stacks, int stack, int *end);
//ALGORYTHM RADIX
void	ft_algorythm_test(int **stacks, int *end);
int		ft_radix(int **stacks, int stack, int *end, int magnitude);
void	ft_algorythm_radix(int **stacks, int *end);
//ALGORYTHM
void	ft_destroy_data(int ***data);
int		ft_cmp_entropy_modifier(int *entropy, int *modifier, int size);
void	ft_algorythm_init(int ***data, int **stacks);
void	ft_algorythm_push_down(int ***data);
void	ft_algorythm(int **stacks);
//SHADOW
void	ft_shadow_init(int ***data);
void	ft_shadow_set(int **stacks, int **shadow, int start_zero,
			int start_one);
//SHADOW MOVES
void	ft_do_push(int **stacks, int stack, int *end, int **shadow);
void	ft_do_rotate(int **stacks, int *end, int **shadow, int target);
void	ft_do_followed(int **stacks, int **shadow, int i);
//ENTROPY
int		ft_entropy_get_unit(int **stacks, int **shadow, int stack, int i);
void	ft_entropy_set_best(int **stacks, int **shadow, int **entropy,
			int stack);
void	ft_entropy_set(int **stacks, int **shadow, int **entropy, int stack);
void	ft_entropy_init(int ***data);
//MODIFIER
void	ft_modifier_set_total(int **modifier, int size);
void	ft_modifier_set_diagonal_one(int ***data, int target);
void	ft_modifier_set(int **entropy, int **modifier, int size);
void	ft_modifier_init(int ***data);
//UTILS
unsigned int	ft_itou(int nb);
int		*ft_arrcpy(int *src, int size);
int		**ft_arr2cpy(int **src, int y, int x);
int		ft_is_next(int a, int b, int stack);
int		ft_is_orded(int **stacks, int stack, int *end);
int		ft_abs(int n);
int		ft_is_in(int **stacks, int stack, int *end, int target);
int		ft_hightest(int **stacks, int stack, int *end);
int		ft_lowest(int **stacks, int stack, int *end);
int		ft_arr_sum_abs(int *arr, int size);

#endif
