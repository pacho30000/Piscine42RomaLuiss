#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>										// da togliere 
typedef struct s_char_option
{
	char	empty;
	char	full;
	char	obstacle;
	int		row_len;
}	t_char_option;

typedef struct s_max_square
{
	int	max_i;
	int	max_j;
	int	max_value;
}	t_max_square;

t_char_option g_c;

int	ft_strlen(char *str);

int ft_atoi (char *s, int i)
{
	int number;
	int n;

	number = 0;
	n = 0;
	while (n <= i - 4) // Mini atoi per convertire il numero in stinga
	{
		number = (number * 10) + (s[n] - 48);
		n++;
	}	
	return (number);
}

int check_first_line (char *s, int i)
{
	int count;
	
	count = 0;
	if (i < 4)
		return (0);
	g_c.full = s[i - 1];
	g_c.obstacle = s[i - 2];
	g_c.empty = s[i - 3];
	g_c.row_len = ft_atoi(s,i);
	while (count < 2)
	{
		if (s[i - 3 + count] == s[i - 1])
			return (0);
		count++;
	}
	if (s[i - 2] == s[i - 3])
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
	int obs;

	x = 0;
	obs = 0;
	c = ft_strlen(*matr);
	if (c < 2 || g_c.row_len < 2)
		return (0);
	while (x < g_c.row_len)
	{
		if (ft_strlen(matr[x]) != c)
			return (0);
		y = 0;
		while (y < c)
		{
			if (matr[x][y] != g_c.empty && matr[x][y] != g_c.obstacle)
				return (0);
			if (matr[x][y] == g_c.obstacle)
				obs++;
			y++;
		}
		x++;
	}
	if (obs == g_c.row_len * c)
		return (0);
	return (1);
}

char	*convert_file_to_str(char *path)
{
	int		size;
	char	c;
	char	*str;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 1)
		exit(-1);
	size = 0;
	while (read(fd, &c, 1) > 0)
		size++;
	str = (char *)malloc(size);
	if (str == NULL)
		exit(-1);
	if (close(fd) == -1)
		exit(-1);
	fd = open(path, O_RDONLY);
	if (fd < 1)
		exit(-1);
	read(fd, str, size);
	if (str[size - 1] != '\n')
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	**convert_str_to_matr(char *str, int row_num)
{
	char	**matrix;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * row_num);
	while (*str != '\n')
		str++;
	str++;
	while (str[len] != '\n')
		len++;
	while (*str != '\0')
	{
		matrix[i] = (char *)malloc(len + 1);
		while (*str != '\n')
		{
			matrix[i][j] = *str++;
			j++;
		}
		matrix[i][j] = '\0';
		j = 0;
		str++;
		i++;
	}
	return (matrix);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while(*str++ != '\0')
		len++;
	return len;
}

int	**alloc_int_matrix(char **matrix_char, int row_num)
{
	int		**matrix_int;
	int		size_row;
	int		i;

	i = 0;
	size_row = ft_strlen(*matrix_char);
	matrix_int = (int **)malloc(sizeof(int *) * row_num);
	while (i < row_num)
	{
		*(matrix_int + i) = (int*)malloc(sizeof(int) * size_row);
		i++;
	}
	return matrix_int;
}

int	sum_diagonals(int up, int left, int left_up)
{
	int	n;

	n = up;
	if (n > left)
		n = left;
	if (n > left_up)
		n = left_up;	
	return (n + 1);
}

void	populate_matrix_int(char **matrix_char, int **matrix_int, int row_num)
{
	int		size_row;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size_row = ft_strlen(*matrix_char);
	while (i < row_num)
	{
		while (j < size_row)
		{
			if (matrix_char[i][j] == g_c.obstacle)
				matrix_int[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix_int[i][j] = 1;
			else
				matrix_int[i][j] = -1;
			j++;
		}
		i++;
		j = 0;
	}
	i = 1;
	j = 1;
	while (i < row_num)
	{
		while (j < size_row)
		{
			if (matrix_int[i][j] == -1)
				matrix_int[i][j] = sum_diagonals(matrix_int[i][j - 1], matrix_int[i - 1][j], matrix_int[i - 1][j - 1]);
			j++;
		}
		i++;
		j = 1;
	}
}

void	write_max_square(char **matr, int **matr_int, int row_num)
{
	int				i;
	int				j;
	t_max_square	max_square;
	int 			col_size;
	int o;

	i = 0;
	j = 0;
	max_square.max_value = 0;
	col_size = ft_strlen(*matr); 
	while (i < row_num)
	{
		while (j < col_size) 
		{
			o = matr_int[i][j];
			if (matr_int[i][j] > max_square.max_value)
			{
				max_square.max_value = matr_int[i][j];
				max_square.max_i = i;
				max_square.max_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = max_square.max_i - max_square.max_value - 1;
	j = max_square.max_j - max_square.max_value;
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	while (i <= max_square.max_i)
	{
		while (j <= max_square.max_j)
		{
			matr[i][j] = g_c.full;
			j++;
		}
		j = max_square.max_j - max_square.max_value;
		i++;
	}
}

int main(int ac, char **ag)
{
	if (ac == 1)
	{
		char *str = convert_file_to_str("s.txt");
		int cond = first_linee("s.txt");
		char **matr = convert_str_to_matr(str, g_c.row_len);
		if (check_linee(matr) == 0 || cond == 0)
		{
			write (1, "map error\n", 10);
			return (0);
		}
		int **int_matr = alloc_int_matrix(matr, g_c.row_len);
		populate_matrix_int(matr, int_matr, g_c.row_len);
		write_max_square(matr, int_matr, g_c.row_len);
	}
	else if (ac > 1)
	{
		int	i;

		i = 0;
		while (i++ < ac)
		{
			char *str = convert_file_to_str(ag[i]);
			int cond = first_linee(ag[i]);
			char **matr = convert_str_to_matr(str, g_c.row_len);
			if (check_linee(matr) == 0 || cond == 0 || matr == NULL)
			{
				write (1, "map error\n", 10);
				if (i + 1 != ac)
					write (1, "\n", 1);	
				continue;
			}
			int **int_matr = alloc_int_matrix(matr, g_c.row_len);
			populate_matrix_int(matr, int_matr, g_c.row_len);
			write_max_square(matr, int_matr, g_c.row_len);
			int j = 0;
			// j = 0;
			while (j < g_c.row_len)
			{
				printf("%s", matr[j]);
				printf("\n");
				j++;
			}
			if (i + 1 != ac)
				write (1, "\n", 1);	
		}
	}
	/*int	i = 0;
	int	j = 0;
	// while (i < N)
	// {
	// 	while (j < N)
	// 	{
	// 		printf("%d ", int_matr[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	j = 0;
	// 	i++;
	// }*/

	
}
