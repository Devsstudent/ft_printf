/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:11:51 by odessein          #+#    #+#             */
/*   Updated: 2022/05/21 14:55:21 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//ft_calc_number_sizeS
//ft_calc_hexa_size
	//CARE OF SIGN if negative compte it in size
	//Precison need to be calc too

void	ft_manage_int(t_storage str, int value)
{
	int	size;

	size = ft_calc_number_size(value);
	ft_apply_rules_before((char *) str.content, size);
	if (ft_check_addsign((char *) str.content))
		wirte(STDOUT_FILENO, "+", 1);
	//display value
	//ft_apply_minus_sign
	//ft_putnbr_calssic
}

void	ft_manage_hexa(t_storage str, unsigned value)
{
	int	size;

	size = ft_calc_hexa_size((char *) str.content, value);
	ft_apply_rules_before(((char *) str.content, size));
	if (ft_check_dieze((char *) str))
		write(STDOUT_FILENO, "0x", 2);
	//ft_putnbr_hexa_conv

}
//ICI care precision reduction works on string (otherwiser not working)
//Need to make a special rules for it
void	ft_manage_string(t_storage str, char *value)
{
	int	size;

	size = ft_strlen(value);
	//putchar with a len depending on precision inputed 
}

void	ft_manage_addr(t_storage str, void *addr)
{
	

}

void	ft_manage_char(t_storage str, char c)
{
		
}
