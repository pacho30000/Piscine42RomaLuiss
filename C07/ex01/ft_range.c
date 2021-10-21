/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:22:29 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/21 13:40:11 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	i = 0;
	range = malloc(sizeof(int) * (max - min));
	if (min >= max || range == 0)
		return (0);
	while (min < max)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
