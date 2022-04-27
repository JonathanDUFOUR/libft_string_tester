/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:16:20 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:44:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;
typedef char			(*t_fct)(char const c);

struct s_test
{
	int const		num;
	char *const		str;
	char const		*expect;
	t_fct const		fct;
	size_t const	size;
};

static t_test const		g_test[] = {
{1,
	(char []){0},
	(char []){0},
	map_tolower, 1},
{2,
	(char []){'t', 'u', 't', 'u', 0},
	(char []){'T', 'U', 'T', 'U', 0},
	map_toupper, 5},
{3,
	(char []){'d', 'i', 'g', 'i', 't', 's', ' ', 'a', 'r', 'e', ' ', 'f', 'u',
	'n', 'n', 'y', 0},
	(char []){'d', '1', '6', '1', '7', '5', ' ', '4', 'r', '3', ' ', 'f', 'u',
	'n', 'n', 'y', 0},
	map_todigit, 17},
{4,
	(char []){0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
	0x0c, 0x0d, 0x0e, 0x0f, 0x00},
	(char []){0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c,
	0x0d, 0x0e, 0x0f, 0x10, 0x00},
	map_increment, 16},
{5,
	(char []){0x01, 0xff, 0x02, 0xfe, 0x03, 0xfd, 0x04, 0xfc, 0x05, 0xfb, 0x06,
	0xfa, 0x07, 0xf9, 0x08, 0xf8, 0x09, 0xf7, 0x0a, 0xf6, 0x0b, 0xf5, 0x0c,
	0xf4, 0x0d, 0xf3, 0x0e, 0xf2, 0x0f, 0xf1, 0x00},
	(char []){0x00, 0xfe, 0x01, 0xfd, 0x02, 0xfc, 0x03, 0xfb, 0x04, 0xfa, 0x05,
	0xf9, 0x06, 0xf8, 0x07, 0xf7, 0x08, 0xf6, 0x09, 0xf5, 0x0a, 0xf4, 0x0b,
	0xf3, 0x0c, 0xf2, 0x0d, 0xf1, 0x0e, 0xf0, 0x00},
	map_decrement, 31},
{6,
	(char []){0x01, 0x06, 0x02, 0x07, 0x03, 0x08, 0x04, 0x09, 0x05, 0x0a, 0x00},
	(char []){0x01, 0x24, 0x04, 0x31, 0x09, 0x40, 0x10, 0x51, 0x19, 0x64, 0x00},
	map_square, 11},
{7,
	(char []){0x5a, 0xe4, 0x21, 0xe2, 0x9f, 0xe9, 0x14, 0x3c, 0xe7, 0x13, 0x09,
	0x2e, 0x23, 0x29, 0xba, 0xc9, 0x5f, 0x40, 0x70, 0x33, 0x15, 0xe7, 0x0f,
	0x7d, 0xc9, 0xd5, 0x00},
	(char []){0xb4, 0xc8, 0x42, 0xc4, 0x3e, 0xd2, 0x28, 0x78, 0xce, 0x26, 0x12,
	0x5c, 0x46, 0x52, 0x74, 0x92, 0xbe, 0x80, 0xe0, 0x66, 0x2a, 0xce, 0x1e,
	0xfa, 0x92, 0xaa, 0x00},
	map_mult_two, 27},
{0}
};

int	test_ft_strmap(int *const ret)
{
	char const	*str;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_strmap(g_test[i].str, g_test[i].fct);
		if (!str)
			return (*ret = FT_STRMAP_ERR);
		result(g_test[i].num,
			!memcmp(str, g_test[i].expect, g_test[i].size));
		free((void *)str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
