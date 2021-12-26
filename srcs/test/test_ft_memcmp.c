/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:06:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/26 04:38:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	uint8_t const	*addr0;
	uint8_t const	*addr1;
	size_t const	n;
};

static t_test const		g_test[] = {
{1,
	(uint8_t[]){},
	(uint8_t[]){},
	0},
{2,
	(uint8_t[]){0x00, 0xf0},
	(uint8_t[]){0x00, 0x01},
	1},
{3,
	(uint8_t[]){0x00, 0xf0, 0x0a},
	(uint8_t[]){0x00, 0x01, 0xa0},
	2},
{4,
	(uint8_t[]){0x22, 0x31, 0x40, 0x99},
	(uint8_t[]){0x11, 0x31, 0x42, 0x99},
	3},
{5,
	(uint8_t[]){0xa0, 0xb1, 0xc2, 0xd3, 0xe4},
	(uint8_t[]){0xa0, 0xb1, 0xc2, 0xdf, 0xe0},
	4},
{6,
	(uint8_t[]){0xa0, 0xb1, 0xc2, 0xd3, 0xe4, 0xf5},
	(uint8_t[]){0xa0, 0xbf, 0xc2, 0xdf, 0xe0, 0xfa},
	5},
{7,
	(uint8_t[]){0xa0, 0xb1, 0xc4, 0xd3, 0xe4, 0xf5, 0x3d},
	(uint8_t[]){0xa0, 0xb1, 0xc2, 0xdf, 0xe0, 0xfa, 0x3d},
	6},
{8,
	(uint8_t[]){0xf0, 0xe1, 0xd2, 0xc3, 0xb4, 0xa5, 0x96, 0x87},
	(uint8_t[]){0xf0, 0xe1, 0xd2, 0xc3, 0xb4, 0xa5, 0x96, 0x00},
	7},
{9,
	(uint8_t[]){0x01, 0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0xaa, 0x8c},
	(uint8_t[]){0x01, 0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0x78, 0xc9},
	8},
{10,
	(uint8_t[]){0x12, 0x21, 0x32, 0x23, 0x43, 0x34, 0x54, 0x45, 0x65, 0xed},
	(uint8_t[]){0x12, 0x21, 0x32, 0x23, 0x43, 0x34, 0x54, 0x45, 0x65, 0x00},
	9},
{11,
	(uint8_t[]){0x15, 0xd1, 0x44, 0x6a, 0x29, 0x84, 0x0b, 0x9f, 0xc3, 0xa1,
	0xbf, 0x02, 0x34, 0x5c, 0x97, 0x00},
	(uint8_t[]){0x15, 0xd1, 0x44, 0x6a, 0x29, 0x84, 0x0b, 0x9f, 0xc3, 0xa1,
	0xbf, 0x02, 0x34, 0x5c, 0xad, 0xe2},
	15},
{0}
};

int	test_ft_memcmp(int *const ret)
{
	int	i;
	int	res0;
	int	res1;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		res0 = memcmp(g_test[i].addr0, g_test[i].addr1, g_test[i].n);
		res0 = !!res0 * (-(res0 < 0) | 1);
		res1 = ft_memcmp(g_test[i].addr0, g_test[i].addr1, g_test[i].n);
		res1 = !!res1 * (-(res1 < 0) | 1);
		result(g_test[i].num,
			res0 == res1);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
