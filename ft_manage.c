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
	t_Bool	add_sign;

	add_sign = false;
	size = ft_calc_number_size(value);
	ft_apply_rules_before((char *) str.content, size);
	if (ft_check_addsign((char *) str.content))
	{
		add_sign = true;
		write(STDOUT_FILENO, "+", 1);
	}
	ft_putnbr((long value));
	ft_apply_minus_sign((char *) str->content, size);
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

	size = ft_strlen_special(value);
	ft_apply_rules_before((char *) str.content, size);
	ft_putnstr(value, size);
	ft_apply_minus_sign((char *) str.content, size)
}

void	ft_manage_addr(t_storage str, void *addr)
{
	unsigned long	addr_conv;
	addr_conv = addr;
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_hexa(addr_conv);
}

void	ft_manage_char(t_storage str, char c)
{
	ft_apply_rules_before((char *) str.content, 1);
	ft_putchar(c);
	ft_apply_minus_sign((char *) str.content, 1);
}
