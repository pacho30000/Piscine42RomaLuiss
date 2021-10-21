#include "utils.h"
extern t_char_option g_c;

int ft_atoi (char *s, int i)
{
	int number;

	number = 0;
	while (i - 5 != -1) // Mini atoi per convertire il numero in stinga
	{
		number = number * 10 + (s[i - 5] + 48);
		i--;
	}	
	return (number);
}

int check_first_line (char *s, int i)
{
	int count;
	
	count = 0;
	if (i < 4)
		return (0);
	g_c.full = s[i - 2];
	g_c.obstacle = s[i - 3];
	g_c.empty = s[i - 4];
	g_c.row_len = ft_atoi(s,i);
	while (count < 2)
	{
		if (s[i - 4 + count] == s[i - 2])
			return (0);
		count++;
	}
	if (s[i - 3] == s[i - 4])
		return(0);
	return (1);		
}

int	first_linee(char *s) // Controlliamo la prima riga e assegniamo i valori alle vaariabili globali.
{
	int fd;
	char *str;
	char c;
	int i;

	i = 0;
	str = (char*) malloc (50);
	fd = open(s, O_RDONLY);
	while (read(fd, &c, 1) > 0)					// Aggiunto indice j a C, perche da errore.
	{
		str[i] = c;
		if ( c == '\n')
			break ;
		if (c < 32 || c == 127)
			return (0);
		i++;
	}
	str[i] = '\0';
	close(fd);
	if(check_first_line(str,i) == 0)
		return (0);
	return (1);
}

int check_linee(char **matr)
{
	int x;
	int c;
	int y;

	x = 1;
	c = ft_strlen(*matr);
	if (c < 2 || g_c.row_len < 2)
		return (0);
	while (x < g_c.row_len)
	{
		if (ft_strlen(matr[x++]) != c)
			return (0);
		y = 0;
		while (y < c)
		{
			if (matr[x][y] != g_c.empty || matr[x][y] != g_c.obstacle)
				return (0);
			y++;
		}
	}
	return (1);
}

