#include "utils.h"

t_char_option g_c;

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

	i = 0;
	j = 0;
	max_square.max_value = 0;
	col_size = ft_strlen(*matr); 
	while (i < row_num)
	{
		while (j < col_size) 
		{
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

int main()
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
	// }

	i = 0;
	j = 0;
	while (i < N)
	{
		printf("%s", matr[i]);
		printf("\n");
		i++;
	}*/
}
