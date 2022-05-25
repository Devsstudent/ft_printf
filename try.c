#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	char c;
	c = 2;
//	ft_printf("%i", ft_printf(" % s % s % s % s % s ", " - ", "", "4", "", "2 "));
//	printf("\n");
//	printf("%i", printf(" % s % s % s % s % s ", " - ", "", "4", "", "2 "));
//	ft_printf("%i", ft_printf(" %10c ", 'b'));
	printf("%i\n", ft_printf("%30p", &c));
	printf("%i", printf("%30p", &c));
}
