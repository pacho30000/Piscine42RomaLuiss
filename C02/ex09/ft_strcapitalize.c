/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:24:39 by pcatapan          #+#    #+#             */
/*   Updated: 2021/10/12 16:28:47 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_small(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_small(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] < 48 && str[i + 1] > 96 && str[i + 1] < 123)
			str[i + 1] = str[i + 1] - 32;
		if (str[i] > 57 && str[i] < 65 && str[i + 1] > 96 && str[i + 1] < 123)
			str[i + 1] = str[i + 1] - 32;
		if (str[i] > 90 && str[i] < 97 && str[i + 1] > 96 && str[i + 1] < 123)
			str[i + 1] = str[i + 1] - 32;
		if (str[i] > 122 && str[i + 1] > 96 && str[i + 1] < 123)
			str[i + 1] = str[i + 1] - 32;
		if (str[0] >= 'a' && str[0] <= 'z')
		{
			str[0] = str[0] - 32;
		}
		i++;
	}
	return (str);
}
