#include <ft_printf.h>
#include <stdio.h>
t_Bool	ft_check_precision_or_not(char *str)
{
	while ((*str && !ft_check_end(*str)) || *str == '%')
	{		
		if (*str == '.')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

void	ft_disp_space_neg(char *str, int size, int space, int *ret_val)
{
	int	prec;
	int	ret;

	ret = space - size;
	while (*str)
	{
		if (*str == '.' && ft_is_digit(*(str + 1)))
		{
			prec = ft_atoi(str + 1);
			if (prec < size)
				prec = size - 1;
			ret = space - (prec + 1);
			break ;
		}
		str++;
	}
	while (ret > 0)
	{
		ft_putchar(' ', ret_val);
		ret--;
	}
}

void	ft_init_struc(t_useful *init)
{
	(*init).prec = FALSE;
	(*init).need_add = FALSE;
	(*init).need_neg = FALSE;
}

int	ft_get_precision(char *str, t_useful *sign)
{
	int	prec;

	prec = 0;
	while ((*str && !ft_check_end(*str)) || *str == '%')
	{
		if (*str == '.' && ft_is_digit(*(str + 1)))
			prec = ft_atoi(str + 1);
		str++;
	}
	if ((*sign).need_neg)
		prec++;
	return (prec);
}

int	ft_disp_space_spe(char *str, int size, t_useful *sign, int *ret_val)
{
	int		nb_of_space;
	int		i;

	i = 1;
	while (!ft_check_end(*(++str)))
	{
		if (ft_is_digit(*str) && !ft_check_minus(str) && *str != '0' && *(str - 1) != '-')
		{
			nb_of_space = ft_atoi(str) - size;
			if (ft_check_precision_or_not(str))
			{
				nb_of_space = ft_atoi(str) - ft_get_precision(str, sign);
				while (nb_of_space > 0)
				{
					ft_putchar(' ', ret_val);
					if (*ret_val == -1)
						return (ft_strlen(str) - 1);
					nb_of_space--;
				}
				while (ft_is_digit(str[i]))
				i++;
			}
		}
		i++;
	}
	return (i);
}
