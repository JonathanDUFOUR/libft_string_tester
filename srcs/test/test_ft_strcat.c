/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:10:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 06:44:37 by jodufour         ###   ########.fr       */
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
	char const		*src;
	char *const		dst0;
	char *const		dst1;
	size_t const	size;
};

static t_test const		g_test[] = {
{1,
	(char []){0, 'N', 'o', 't', 'h', 'i', 'n', 'g'},
	(char []){'3', '2', '1', 0, '#', '$', '%', '@', '!'},
	(char []){'3', '2', '1', 0, '#', '$', '%', '@', '!'},
	9},
{2,
	(char []){'W', 'h', 'a', 't', 's', ' ', 'u', 'p', 0},
	(char []){'H', 'i', 0, 'g', 'a', 'r', 'b', 'a', 'g', 'e', '.', '.', '.'},
	(char []){'H', 'i', 0, 'g', 'a', 'r', 'b', 'a', 'g', 'e', '.', '.', '.'},
	13},
{3,
	(char []){'f', 'z', 'e', 'r', 'o', 0, 'd', 'o', 'o', 'm'},
	(char []){'k', 'o', 'a', 'l', 'a', 0, 'k', 'i', 'n', 'g', ' ', 'f', 'o',
	'r', 'e', 'v', 'e', 'r', 0},
	(char []){'k', 'o', 'a', 'l', 'a', 0, 'k', 'i', 'n', 'g', ' ', 'f', 'o',
	'r', 'e', 'v', 'e', 'r', 0},
	19},
{4,
	(char []){'B', 'e', ' ', 'h', 'a', 'p', 'p', 'y', 0},
	(char []){'D', 'o', 'n', 't', ' ', 'w', 'o', 'r', 'r', 'y', ' ', 0, 'D',
	'a', 'n', 's', 'e', ' ', 'w', 'i', 't', 'h', ' ', 'm', 'e', 0},
	(char []){'D', 'o', 'n', 't', ' ', 'w', 'o', 'r', 'r', 'y', ' ', 0, 'D',
	'a', 'n', 's', 'e', ' ', 'w', 'i', 't', 'h', ' ', 'm', 'e', 0},
	26},
{5,
	(char []){'A', 'B', 'B', 'A', 0, 0, 0, 0},
	(char []){'H', 'e', 'l', 'l', 'o', ' ', 'd', 'a', 'r', 'k', 'n', 'e', 's',
	's', ',', ' ', 'm', 'y', ' ', 'o', 'l', 'd', 'f', 'r', 'i', 'e', 'n', 'd',
	0, 'I', '\'', 'v', 'e', ' ', 'c', 'o', 'm', 'e', ' ', 'n', 'o', 'w'},
	(char []){'H', 'e', 'l', 'l', 'o', ' ', 'd', 'a', 'r', 'k', 'n', 'e', 's',
	's', ',', ' ', 'm', 'y', ' ', 'o', 'l', 'd', 'f', 'r', 'i', 'e', 'n', 'd',
	0, 'I', '\'', 'v', 'e', ' ', 'c', 'o', 'm', 'e', ' ', 'n', 'o', 'w'},
	42},
{6,
	(char []){'P', 'r', 'o', 'g', 'r', 'a', 'm', ' ', 'i', 'n', ' ', 'C', ' ',
	'!', ' ', 'A', 'n', 'd', ' ', 'b', 'e', 'c', 'o', 'm', 'e', ' ', 'a', ' ',
	't', 'r', 'u', 'e', ' ', 'd', 'e', 'v', 'e', 'l', 'o', 'p', 'p', 'e', 'r',
	0},
	(char []){0, 'J', 'a', 'v', 'a', ' ', 'i', 's', ' ', 'n', 'o', 't', ' ',
	's', 'o', ' ', 'b', 'a', 'd', ',', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a',
	'l', 'l', '.', '.', '.', ' ', 'D', 'o', 'n', 't', ' ', 'y', 'o', 'u', ' ',
	'a', 'g', 'r', 'e', 'e', ' ', '?'},
	(char []){0, 'J', 'a', 'v', 'a', ' ', 'i', 's', ' ', 'n', 'o', 't', ' ',
	's', 'o', ' ', 'b', 'a', 'd', ',', ' ', 'a', 'f', 't', 'e', 'r', ' ', 'a',
	'l', 'l', '.', '.', '.', ' ', 'D', 'o', 'n', 't', ' ', 'y', 'o', 'u', ' ',
	'a', 'g', 'r', 'e', 'e', ' ', '?'},
	50},
{7,
	(char []){'T', 'a', 'k', 'e', ' ', 'o', 'n', ' ', 'm', 'e', 0},
	(char []){'N', 'e', 'v', 'e', 'r', ' ', 'g', 'o', 'n', 'n', 'a', ' ', 'g',
	'i', 'v', 'e', ' ', 'y', 'o', 'u', ' ', 'u', 'p', '.', 0, 'N', 'e', 'v',
	'e', 'r', ' ', 'g', 'o', 'n', 'n', 'a', ' ', 'l', 'e', 't', ' ', 'y', 'o',
	'u', ' ', 'd', 'o', 'w', 'n', '.', 0},
	(char []){'N', 'e', 'v', 'e', 'r', ' ', 'g', 'o', 'n', 'n', 'a', ' ', 'g',
	'i', 'v', 'e', ' ', 'y', 'o', 'u', ' ', 'u', 'p', '.', 0, 'N', 'e', 'v',
	'e', 'r', ' ', 'g', 'o', 'n', 'n', 'a', ' ', 'l', 'e', 't', ' ', 'y', 'o',
	'u', ' ', 'd', 'o', 'w', 'n', '.', 0},
	51},
{0}
};

int	test_ft_strcat(int *const ret)
{
	char	*dst0;
	char	*dst1;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		dst0 = strcat(g_test[i].dst0, g_test[i].src);
		dst1 = ft_strcat(g_test[i].dst1, g_test[i].src);
		result(g_test[i].num,
			dst0 - g_test[i].dst0 == dst1 - g_test[i].dst1
			&& !memcmp(g_test[i].dst0, g_test[i].dst1, g_test[i].size));
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
