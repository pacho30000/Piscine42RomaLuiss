/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:28:47 by fgiulian          #+#    #+#             */
/*   Updated: 2021/10/05 15:01:04 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"ft_putchar.c"

void	funz_if(int a, int b, int x, int y)
{
	if ((a == 1 && b == 1) || (a == x && b == y && a == b))
		ft_putchar('/');
	if ((a == 1 && b == y && a != b) || (a == x && b == 1 && a != b))
		ft_putchar(92);
	{
		if ((a == 1 && (b != 1 && b != y)) || (a == x && (b != 1 && b != y)))
			ft_putchar('*');
		if ((b == y && (a != 1 && a != x)) || (b == 1 && (a != 1 && a != x)))
			ft_putchar('*');
		if (b == y || a == x || a == 1 || b == 1)
			;
		else
			ft_putchar(' ');
	}
	if (a == x && b != y)
		ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	a;
	int	b;

	b = 0;
	while (b < y)
	{
		a = 0;
		while (a < x)
		{
			funz_if(a, b, x, y);
			a++;
		}
		b++;
	}
}
