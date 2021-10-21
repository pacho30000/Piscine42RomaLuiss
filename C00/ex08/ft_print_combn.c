/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:51:09 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/05 21:49:55 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print(int *p, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf ("%d", p[i++]);
	}
	printf(", ");
}

void	a(int *p, int n)
{
	while (p[0] != 10 - n)
	{
		int	i;
		int	j;

		i = 1;
		j = 0;
		while (p [n - 1] <= 9)
		{
			print(p, n);
			p[n - 1] += 1;
		}
		while (1)
		{
			if (p[n - 1 - i] == p[n - 1 - j] - 1)
			{
				i++;
				j++;
			}
			else
			{
				p[n - 1 - i] += 1;
				break;
			}
		}
		int	k;

		k = 1;
		j = 0;
		while (1)
		{
			if ((n - 1 - i + j) == n - 1)
				break;
			p[n - 1 - i + k] = p[n - 1 - i + j] + 1;
			k++;
			j++;
		}
	}
	print(p, n);
}

int	main() {
  int	n = 2;
  int	p[n];
  int	i = 0;
  while (i < n ) {
    p[i] = i;
    i++;
  }
  a(p,n);
}
