/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:18:05 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/21 23:01:26 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *total, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*find)
		return ((char *)(total));
	if (n > ft_strlen(total))
		n = ft_strlen(total);
	while (j < n)
	{
		while (find[i] != total[j] && j < n)
			j++;
		while (find[i] == total[j] && j < n)
		{
			i++;
			j++;
		}
		if (!find[i])
			return ((char *)(total + (j - i)));
		j = j - i + 1;
		i = 0;
	}
	return (NULL);
}
