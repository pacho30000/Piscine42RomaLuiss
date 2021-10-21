/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:28:58 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/18 22:26:24 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int nbr)
{
	write(1, &nbr, 1);
}

int	ft_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_controll(char *base)
{
	int	i;
	int	j;

	if (base == 0 || ft_len(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			if (base[j] == '+' || base[j] == '-')
				return (0);
			if ((base[j] == 32 || base[j] > 8) && base[j] < 14)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_controll(base) == 1)
	{
		if (nbr == -2147483648)
		{
			ft_putnbr_base(nbr / ft_len(base), base);
			ft_putchar(base[(nbr % ft_len(base)) * -1]);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			ft_putnbr_base(-nbr, base);
		}
		else if (nbr >= ft_len(base))
		{
			ft_putnbr_base(nbr / ft_len(base), base);
			ft_putchar(base[nbr % ft_len(base)]);
		}
		else if (nbr >= 0)
		{
			ft_putchar(base[nbr % ft_len(base)]);
		}
	}	
}
