/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:47:13 by odessein          #+#    #+#             */
/*   Updated: 2022/05/21 14:43:35 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

void	ft_apply_rules_before(char *str, int size, t_Bool *zero_or_not)
{
	int	i;

	i = 1;
	while (!ft_check_end(str[i]))
	{
		if (str[i] == ' ' && str[i + 1] != '0')
			ft_putchar(' ');
		if (str[i] == '0' && ft_is_digit(str[i + 1]))
		{
			size = ft_need_sign(str, size, zero_or_not);
			i = ft_disp_zero(str, size, i + 1);
		}
		if (str[i] == '.')
			return ;
		if (ft_is_digit(str[i]) && !ft_check_minus(str))
		{
			i = ft_disp_space(str, size, i);
		}
		i++;
	}
}

void	ft_apply_minus_sign(char *str, int size)
{
	int	i;

	i = 1;
	if (ft_check_space(str, 0))
		size++;
	while (!(ft_check_end(str[i])))
	{
		if (str[i] == '-' && ft_is_digit(str[i + 1]))
			ft_disp_space(str, size, i + 1);
		i++;
	}
}

void	ft_precision(char *str, int size, t_Bool *add_sign)
{
	int		nb_of_zero;
	int		i;
	int		len;
	char	*to_free;
	int		buff_idx;

	len = 0;
	i = 1;
	while (!ft_check_end(str[i]))
	{
		if (str[i] == '.' && ft_is_digit(str[i+ 1]))
		{
			buff_idx = i + 1;
			size = ft_need_sign(str, size, add_sign);
			while (ft_is_digit(str[++i]))
				len++;
			to_free = ft_substr(str, buff_idx, len);
			nb_of_zero = ft_atoi(to_free) - size;
			free(to_free);
			while (nb_of_zero > 0)
			{
				ft_putchar('0');
				nb_of_zero--;
			}
			return ;
		}
		i++;
	}
}

int	ft_disp_zero(char *str, int size, int index)
{
	//atoi un sub str pour avoir la value de buf_index
	int		nb_of_zero;
	int		buff_index;
	int		len;
	char	*to_free;

	// function qui check if a space before index if it is print 1 less 0
	if (ft_check_space(str, index))
		size++;
	len = 0;
	buff_index = index;
	while (ft_is_digit(str[index]))
	{
		len++;
		index++;
	}
	to_free = ft_substr(str, buff_index, len);
	nb_of_zero = ft_atoi(to_free) - size;
	free(to_free);
	while (nb_of_zero > 0)
	{
		write(STDOUT_FILENO, "0", 1);
		nb_of_zero--;
	}
	return (index);
}

int	ft_disp_space(char *str, int size, int index)
{
	int		nb_of_space;
	int		buff_index;
	int		len;
	char	*to_free;

	len = 0;
	buff_index = index;
	while (ft_is_digit(str[index]))
	{
		len++;
		index++;
	}
	to_free = ft_substr(str, buff_index, len);
	nb_of_space = ft_atoi(to_free) - size;
	nb_of_space = ft_check_precision(str, nb_of_space, size);
	free(to_free);
	while (nb_of_space > 0)
	{
		ft_putchar(' ');
		nb_of_space--;
	}
	return (index);
}
