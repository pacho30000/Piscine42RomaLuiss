/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:48:05 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/18 22:33:30 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(int nb, char *base)
{
	#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb *= -1);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + 48);
	}
}

int	ft_controllstr(char *str)
{
	int	i;
	int	s;
	int	number;

	number = 0;
	s = 1;
	i = 0;
	while (str[i] != '\0')
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
			number = (number * 10) + (str[i] - 48);
			i++;
		}
		number = number * s;
		return (number);
	}
	return (0);
}

int	ft_controll( char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base == 0 || ft_len(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			if (base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;

	if (ft_controll(base) == 1)
		;
	if (ft_controllstr(str) != 0)
	{
		nb = ft_controllstr(str);
		ft_putchar(nb, base);
	}
	return (0);
}
