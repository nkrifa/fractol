/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:18:05 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/21 23:39:39 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_round(double x)
{
	if (x > 0 && (long)x < (long)(x + 0.5))
		return ((double)(long)(x + 1));
	if (x < 0 && (long)x > (long)(x - 0.5))
		return ((double)(long)(x - 1));
	return ((double)(long)x);
}
