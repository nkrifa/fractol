/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:18:05 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/21 22:59:15 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (n--)
	{
		if (((UC *)s1)[i] != ((UC *)s2)[i])
			return (((UC *)s1)[i] - ((UC *)s2)[i]);
		i++;
	}
	return (0);
}