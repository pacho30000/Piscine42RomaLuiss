/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:20:00 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/18 17:54:48 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	number;

	s = 1;
	i = 0;
	number = 0;
	if (str != '\0')
	{
		while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i++] == '-')
				s *= -1;
		}
		while (str[i] > 47 && str[i] < 58)
		{
			number = number * 10 + (str[i] - 48);
			i++;
		}
		return (number * s);
	}
	return (0);
}
