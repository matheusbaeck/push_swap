/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:31:50 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/02/23 19:33:03 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(len_s1 > SIZE_T_MAX) && !(len_s2 > SIZE_T_MAX))
	{
		s3 = malloc((len_s1 + len_s2 + 1) * sizeof(char));
		if (!s3)
			return (0);
		if (ft_strlcpy(s3, s1, len_s1 + 1) == ft_strlen(s3)
			&& ft_strlcpy(&s3[len_s1], s2, len_s2 + 1)
			== ft_strlen(&s3[len_s1]))
			return (s3);
	}
	return (0);
}
