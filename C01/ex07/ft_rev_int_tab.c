/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:25:47 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/13 12:43:58 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tem;

	i = 0;
	while (i < size / 2)
	{
		tem = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tem;
		i++;
	}
}
