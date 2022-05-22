//header

t_Bool	ft_handle_err(char *str)
{
	char	type;
	int	i;
	t_Bool	error;

	i = 1;
	error = false;
	while (str[i])
	{
		if (ft_check_end(str[i]))
			type = str[i];
		i++;
	}
	if (type == 'd' || type == 'i' || type == 'u')
		ft_check_comb_nb(str, &error);
	else if (type == 'x' || type == 'X')
		ft_check_comb_hex(str, &error);
	else if (type == 'p')
		ft_check_comb_addr(str, &error);
	else if (type == 's')
		ft_check_comb_string(str, &error);
	else if (type == 'c')
		ft_check_comb_char(str, &error);
	if(error)
		return (true);
	return  (false);
}

void	ft_check_comb_nb(char *str, t_Bool *error)
{
	
}

void	ft_check_comb_hex(char *str, t_Bool *error)
{


}

void	ft_check_comb_string(char *str, t_Bool *error)
{

}

void	ft_check_comb_addr(char *str, t_Bool *error)
{

}
