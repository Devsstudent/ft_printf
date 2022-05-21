/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:11:48 by odessein          #+#    #+#             */
/*   Updated: 2022/05/21 13:14:39 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_calc_number_size(char *str, int value)
{
	long	val;
	int		size;

	//ft_check_+; if yes size++; && value not < 0
	val = value;
	size = 0;
	if (val < 0)
	{
		val = val * (-1);
		size++;
	}
	if (val == 0)
		return (1);
	while (val > 0)
	{
		val = val/10;
		size++;
	}
	return (size);
}

int	ft_calc_hexa_size(char *str, unsigned value)
{
	long		val;
	int			size;
	long		index;
	int			i;
	long		buff;

	index = ft_calc_number_size((int) value) - 1;
	val = value;
	buff = val;
	i = 0;
	size = 0;
	if (val == 0)
		size++;
	while (val != 0 && val % ft_power(16, index) == buff)
		val =  val % ft_power(16, index--);
	while (val > 0)
	{
		val =  val % ft_power(16, index);
		size++;
		index--;
	}
	//ft_check_dieze 
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			size = size + 2;
		i++;
	}
	return (size);
}
