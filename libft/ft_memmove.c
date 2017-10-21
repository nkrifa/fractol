/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:18:05 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/21 22:59:28 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	UC	*str1;
	UC	*str2;

	str1 = (UC *)dst;
	str2 = (UC *)src;
	if (dst > src)
	{
		str1 = str1 + len;
		str2 = str2 + len;
		while (len--)
			*--str1 = *--str2;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
