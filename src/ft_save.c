
int	ft_disp_space(char *str, int size, t_useful *sign, int *ret_val)
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
