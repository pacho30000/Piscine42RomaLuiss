/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:20:55 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/05 12:17:15 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print(char e, char f, char g, char h)
{
	ft_putchar(e);
	ft_putchar(f);
	ft_putchar(' ');
	ft_putchar(g);
	ft_putchar(h);
	if (e != '9' | f != '8' | g != '9' | h != '9')
		write (1, ", ", 2);
}

void	ft_print_comb2(void)
{
	char	e;
	char	f;
	char	g;
	char	h;
	{
		e = '0' - 1;
		while (++e <= '9')
		{
			f = '0' - 1;
			while (++f <= '9')
			{
				g = e - 1;
				while (++g <= '9')
				{
					h = f;
					while (++h <= '9')
						ft_print(e, f, g, h);
					h--;
				}
			}
		}
	}
}
