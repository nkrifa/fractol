/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:18:05 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/21 23:37:57 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((UC *)s)[i] == (UC)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
