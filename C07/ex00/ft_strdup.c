/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:14:40 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/19 10:22:25 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_len(src)
{
	int  i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	char *dest;
	int i;

	dest = (char *) malloc  (sizeof (*dest) * (ft_len(src) + 1));
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
