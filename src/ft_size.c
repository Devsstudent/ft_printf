/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:11:48 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 19:07:13 by odessein         ###   ########.fr       */
/*                                                                            */ /* ************************************************************************** */ 
#include "ft_printf.h"
#include <stdio.h>
size_t	ft_strlen_special(char *s, char *pattern)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (!ft_check_end(pattern[++i]))
	{
		if (pattern[i] == '.' && pattern[i + 1] == 's')
			return (0);
		if (pattern[i] == '.' && ft_is_digit(pattern[i + 1]))
		{
			size = ft_atoi(&pattern[i + 1]);
			return (size);
		} 
	}
	if (!s)
		return (6);
	while (s[size] != '\0')
		size++;
	return (size);
}

int	ft_calc_number_size(unsigned long value, char *str)
{
	long	val;
	int		size;

	val = value;
	size = 0;
	if (val < 0)
	{
		val = val * (-1);
		size++;
	}
	if (val == 0 && !ft_check_novalue(str, (int) value))
		return (1);
	while (val > 0)
	{
		val = val / 10;
		size++;
	}
	return (size);
}

int	ft_calc_hexa_size(char *str, unsigned int value)
{
	long		val;
	int			size;
	long		index;
	int			i;
	long		buff;

	index = ft_calc_number_size((unsigned long) value, str);
	val = value;
	buff = val;
	i = 0;
	size = 0;
	if (val == 0)
		size++;
	while (val != 0 && val % ft_power(16, index) == buff)
		val = val % ft_power(16, index--);

	while (val > 0)
	{
		buff = val;
		val = val % ft_power(16, index);
		if (val ==  0 && buff - ft_power(16, index) > 0 && index > 0)
			val = buff - ft_power(16, index);
		size++;
		index--;
	}
	while (str[i] != '\0')
		if (str[i++] == '#')
			size = size + 2;
	return (size);
}

int	ft_check_precision(char *str, int expected_space, int size)
{
	int	i;
	int	nb_of_zero;

	i = 1;
	while (!ft_check_end(str[i]))
	{
		if (str[i] == '.' && ft_is_digit(str[i + 1]))
		{
			nb_of_zero = ft_atoi(&str[i + 1]) - size;
			if (nb_of_zero < 0)
				nb_of_zero *= -1;
			return (expected_space - nb_of_zero);
		}
		i++;
	}
	return (expected_space);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}