/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:58:50 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 15:14:15 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_power(long number, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (number);
	else
		return (number * ft_power(number, power - 1));
}

void	ft_putchar(char c, int *ret_val)
{
	if (write(STDOUT_FILENO, &c, 1))
		(*ret_val)++;
	else
		(*ret_val) = -1;
}

void	ft_putnbr_addr(unsigned long nb, int *ret_val)
{
	if (nb < 16)
	{
		ft_putchar(BASE_L[nb], ret_val);
		return ;
	}
	ft_putnbr(nb / 16, false, ret_val);
	ft_putchar(BASE_L[nb % 16], ret_val);
	if (*ret_val == -1)
		return ;
}

t_Bool	ft_check_minus(char *str)
{
	while (*str)
	{
		if (*str == '-')
			return (true);
		str++;
	}
	return (false);
}
