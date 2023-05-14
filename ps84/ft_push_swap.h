/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:03:06 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/05/12 00:48:37 by mamagalh@st      ###   ########.fr       */
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

int				ft_str_count(char *argv);
int				ft_check_duplicity(int *numbers);
int				ft_check_isalldigit(int argc, char **argv);
int				*ft_get_numbers(int argc, int size, char **argv);
void			ft_normalize(int **stacks, int *end);
int				ft_swap(int **stacks, int stack, int *end, int mod);
int				ft_push(int **stacks, int stack, int *end, int mod);
int				ft_rotate(int **stacks, int stack, int *end, int mod);
int				ft_rev_rotate(int **stacks, int stack, int *end, int mod);
void			ft_algorythm_test(int **stacks, int *end);
int				ft_radix(int **stacks, int stack, int *end, int magnitude);
void			ft_algorythm_radix(int **stacks, int *end);
int				ft_hightest(int **stacks, int stack, int *end);
int				ft_lowest(int **stacks, int stack, int *end);
void			ft_algorythm_3n(int **stacks, int stack, int *end);
void			ft_algorythm_5n(int **stacks, int stack, int *end);
unsigned int	ft_itou(int nb);
int				*ft_arrcpy(int *src, int size);
int				**ft_arr2cpy(int **src, int y, int x);
int				ft_is_next(int a, int b, int stack);
int				ft_is_orded(int **stacks, int stack, int *end);

#endif
