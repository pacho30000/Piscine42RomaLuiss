#ifndef UTILS_H
#define UTILS_H
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

int	first_linee(char *s);
int ft_atoi (char *s, int i);
int check_first_line (char *s, int i);
int	first_linee(char *s);
int check_linee(char **matr);
char	*convert_file_to_str(char *path);
char	**convert_str_to_matr(char *str, int row_num);
int	ft_strlen(char *str);
int	**alloc_int_matrix(char **matrix_char, int row_num);
int	sum_diagonals(int up, int left, int left_up);
void	populate_matrix_int(char **matrix_char, int **matrix_int, int row_num);
void	write_max_square(char **matr, int **matr_int, int row_num);
#endif