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

size_t	ft_strlen_special(char *s, char *pattern)
{
	size_t	size;
	int	i;
	char	*to_free;
	int	len;
	int	buff_idx;

	size = 0;
	i = 1;
	len = 0;
	while (!ft_check_end(pattern[i]))
	{
		if (pattern[i] == '.' && pattern[i + 1] == 's')
			return (0);
		if (pattern[i] == '.' && ft_is_digit(pattern[i + 1]))
		{
			buff_idx = ++i;
			while (ft_is_digit(pattern[i]))
			{
				len++;
				i++;
			}
			to_free = ft_substr(pattern, buff_idx, len);
			size = ft_atoi(to_free);
			free(to_free);
			if (size < 0)
				size = 0;
			return (size);
		}
		i++;
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
	int	buff_idx;
	char	*to_free;
	int	nb_of_zero;
	int	len;

	i = 1;
	len = 0;
	while (!ft_check_end(str[i]))
	{
		if (str[i] == '.' && ft_is_digit(str[i + 1]))
		{
			buff_idx = i + 1;
			while (ft_is_digit(str[++i]))
				len++;
			to_free = ft_substr(str, buff_idx, len);
			nb_of_zero = ft_atoi(to_free) - size;
			free(to_free);
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
