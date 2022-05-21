/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:01:11 by odessein          #+#    #+#             */
/*   Updated: 2022/05/08 17:52:42 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_manage_unsigned(t_storage str, unsigned value)
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
	ft_putnbr_unsigned((value));
	ft_apply_minus_sign((char *) str->content, size);
}

void	ft_putnbr(long nb, t_Bool add_sign)
{
	if (nb < 0)
	{
		nb = nb * (-1);
		if (!add_sign)
			ft_putchar('-');
	}

	if (nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	ft_putnbr(nb / 10, add_sign)
	ft_putchar((nb % 10) + 48);
}

void	ft_putnbr_hexa(unsigned nb)
{
	if (nb < 16)
	{
		ft_putchar(BASE_L[nb]);
		return ;
	}
	ft_putnbr(nb / 16);
	ft_putchar(BASE_L[nb % 16]);
}

void	ft_putnbr_hexa_X(unsigned nb)
{
	if (nb < 16)
	{
		ft_putchar(BASE_U[nb]);
		return ;
	}
	ft_putnbr(nb / 16);
	ft_putchar(BASE_U[nb % 16]);
}

void	ft_putnbr_unsigned(unsigned nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	ft_putnbr(nb / 10)
	ft_putchar((nb % 10) + 48);
}
