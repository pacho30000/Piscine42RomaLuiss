/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:34:36 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/19 22:40:00 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt_recur(int nb, int nb2)
{
	if (nb > 2147395600)
		return (0);
	if (nb2 * nb2 == nb)
		return (nb2);
	if (nb2 * nb2 < nb)
		return (ft_sqrt_recur(nb, nb2 + 1));
	return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_sqrt_recur(nb, 0));
}
