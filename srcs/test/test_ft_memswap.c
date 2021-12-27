/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memswap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:08:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 04:24:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_string.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	uint8_t const	a;
	uint8_t const	b;
};

static t_test const		g_test[] = {
{1, 0x00, 0x00},
{2, 0x01, 0x00},
{3, 0x00, 0x02},
{4, 0x01, 0x02},
{5, 0xa0, 0x0a},
{6, 0xde, 0xab},
{7, 0xff, 0x42},
{0}
};

int	test_ft_memswap(int *const ret)
{
	uint8_t	a;
	uint8_t	b;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		a = g_test[i].a;
		b = g_test[i].b;
		ft_memswap(&a, &b);
		result(g_test[i].num,
			a == g_test[i].b && b == g_test[i].a);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
