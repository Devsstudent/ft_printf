#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	ft_printf(" %i", ft_printf(" %010x", INT_MIN));
	printf("\n");
	printf("%i", printf(" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}
