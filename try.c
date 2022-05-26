#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	char *c;
	c = NULL;
	//printf("%i\n", ft_printf("as soon as %-10possible", (void *) -1));
//	printf("%i\n", printf("as soon as %-10possible", (void *) -1));
	printf("%i\n",  ft_printf("%-8p", (void *) -1));
	printf("%i\n",  printf("%-8p", (void *) -1));


}
