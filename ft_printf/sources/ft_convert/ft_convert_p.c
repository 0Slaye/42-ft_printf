/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:17:34 by uwywijas          #+#    #+#             */
/*   Updated: 2023/11/28 20:37:44 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_counthexa(unsigned long long value)
{
	if (value < 16)
		return (1);
	return (1 + ft_counthexa(value / 16));
}

static void	ft_puthexa_lower(unsigned long long value)
{
	if (!value)
		return ;
	if (value >= 16)
		ft_puthexa_lower(value / 16);
	ft_putchar_fd("0123456789abcdef\0"[value % 16], 1);
}

int	ft_convert_p(void *value)
{
	if (!value)
		return (ft_putstr_fd("0x0", 1), 3);
	ft_putstr_fd("0x", 1);
	ft_puthexa_lower((unsigned long) value);
	return (ft_counthexa((unsigned long) value) + 2);
}
