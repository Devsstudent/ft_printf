/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_varidic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:10:31 by odessein          #+#    #+#             */
/*   Updated: 2022/05/19 13:53:29 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *c)
{
	while (*c)
	{
		ft_putchar(*c);
		c++;
	}
}
void	ft_test(char *str, ...)
{
	va_list	ap;
	char	d;
	char	*st;
	int		nb;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{	
			st = va_arg(ap, char*);
			ft_putstr(st);
		}
		if (*str == 'c')
		{
			d = va_arg(ap, int);
			printf("%c", d);
			ft_putchar(d + 48);
		}
		str++;
	}
	va_end(ap);
}

int	main(int ac, char *av[])
{
	ft_test(av[1], 1);
}
