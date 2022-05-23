/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:11:48 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 15:43:33 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

size_t	ft_strlen_special(char *s, char *pattern)
{
	size_t	size;
	int		i;
	char	*to_free;
	int		len;
	int		buff_idx;

	size = 0;
	i = 0;
	len = 0;
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
	while (s[size] != '\0')
		size++;
	return (size);
}

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

	index = ft_calc_number_size(str, (int) value) - 1;
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
