/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:43:43 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/11 14:54:30 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int tmp;

	tmp = 0;
	if (n >= 0)
		tmp = n;
	if (n < 0)
	{
		ft_putchar('-');
		tmp = (unsigned int)(n * -1);
	}
	if (tmp > 9)
	{
		ft_putnbr(tmp / 10);
		ft_putchar(tmp % 10 + '0');
	}
	else
		ft_putchar(tmp + '0');
}
