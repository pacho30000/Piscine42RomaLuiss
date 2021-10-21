#include <stdio.h>
#include "ex00/ft_ft.c"
#include "ex01/ft_ultimate_ft.c"
#include "ex02/ft_swap.c"
#include "ex03/ft_div_mod.c"
#include "ex04/ft_ultimate_div_mod.c"
#include "ex05/ft_putstr.c"
#include "ex06/ft_strlen.c"
#include "ex07/ft_rev_int_tab.c"
#include "ex08/ft_sort_int_tab.c"

int main()
{
	int i, j, h, div, mod ;
	char *chaine;
	int list[4] = {2, 1, 5, 9};
	i = 2;
	j = 24;
	int a;
	int *ptr1, **ptr2, ***ptr3, ****ptr4, *****ptr5, ******ptr6, *******ptr7, ********ptr8, *********ptr9;

	a = 21;
	ptr1 = &a;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;

	chaine = "everything is fine";

	printf("\nex00/ft_ft\n");
	printf("Before (2): %d\n", i);
	ft_ft(&i);
	printf("After (42): %d\n", i);

	printf("\nex01/ft_ultimate_ft\n");
	printf("Before (21): %d\n", a);
	ft_ultimate_ft(ptr9);
	printf("After (42): %d\n", a);

	printf("\nex02/ft_swap\n");
	printf("Before: j = %d i = %d\n", j, i);
	ft_swap(&i, &j);
	printf("After: j = %d, i = %d\n", j, i);

	printf("\nex03/ft_div_mod\n");
	printf("Before: j = %d i = %d\n", j, i);
	ft_div_mod(j, i, &div, &mod);
	printf("After: mod = %d div = %d\n", mod, div);

	printf("\nex04/ft_ultimate_div_mod\n");
	printf("Before: j = %d i = %d\n", j, i);
	ft_ultimate_div_mod(&j, &i);
	printf("After: j = %d i = %d\n", j, i);

	printf("\nex05/ft_putstr\n");
	ft_putstr(chaine);
	printf("\n");

	printf("\nex06/ft_strlen\n");
	printf("The character string contains %d characters\n", ft_strlen(chaine));

	printf("\nex07/ft_rev_int_tab\n");
	ft_rev_int_tab(list, 4);

	h = 0;
	printf("Before = ");
	while (h < 4)
		printf("%d", list[h++]);
	ft_rev_int_tab(list, 4);

	h = 0;
	printf("\nAfter = ");
	while (h < 4)
		printf("%d", list[h++]);

	printf("\n\nex08/ft_sort_int_tab\n");
	printf("Before = ");
	h = 0;
	while (h < 4)
		printf("%d", list[h++]);

	printf("\nAfter = ");
	h = 0;
    ft_sort_int_tab(list, 4);
	while (h < 4)
		printf("%d", list[h++]);
	return 0;
}
