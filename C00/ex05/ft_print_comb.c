/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:35:04 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/05 19:05:56 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print(char d, char e, char f)
{
	ft_putchar(d);
	ft_putchar(e);
	ft_putchar(f);
}

void	ft_print_comb(void)
{
	char	d;
	char	f;
	char	e;

	d = '0';
	while (d <= '7')
	{
		e = d + 1;
		while (e <= '8')
		{
			f = e + 1;
			while (f <= '9')
			{
				ft_print(d, e, f);
				if (d != '7' | e != '8' | f != '9')
					write (1, ", ", 2);
				f++;
			}
			e++;
		}
		d++;
	}
}
