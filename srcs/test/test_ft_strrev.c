/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:19:19 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:45:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char *const	str;
	char const	*expect;
};

static t_test const		g_test[] = {
{1,
	(char []){0},
	(char []){0}},
{2,
	(char []){'A', 0},
	(char []){'A', 0}},
{3,
	(char []){'b', 'A', 0},
	(char []){'A', 'b', 0}},
{4,
	(char []){'C', 'D', 'E', 0},
	(char []){'E', 'D', 'C', 0}},
{5,
	(char []){'k', 'o', 'a', 'l', 'a', 0},
	(char []){'a', 'l', 'a', 'o', 'k', 0}},
{6,
	(char []){'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 0},
	(char []){'9', '8', '7', '6', '5', '4', '3', '2', '1', '0', 0}},
{7,
	(char []){'M', 'a', 's', 't', 'e', 'r', ' ', 'G', 'a', 'n', 'd', 'a', 'l',
	'f', ' ', 'i', 's', ' ', 'a', ' ', 'w', 'h', 'i', 't', 'e', ' ', 'w', 'i',
	'z', 'a', 'r', 'd', '.', ' ', 'H', 'e', ' ', 'w', 'i', 'l', 'l', ' ', 'g',
	'u', 'i', 'd', 'e', ' ', 'u', 's', ',', ' ', 'a', 'n', 'd', ' ', 'w', 'e',
	' ', 's', 'h', 'e', 'l', 'l', ' ', 'n', 'o', 't', ' ', 'p', 'a', 't', 'h',
	0},
	(char []){'h', 't', 'a', 'p', ' ', 't', 'o', 'n', ' ', 'l', 'l', 'e', 'h',
	's', ' ', 'e', 'w', ' ', 'd', 'n', 'a', ' ', ',', 's', 'u', ' ', 'e', 'd',
	'i', 'u', 'g', ' ', 'l', 'l', 'i', 'w', ' ', 'e', 'H', ' ', '.', 'd', 'r',
	'a', 'z', 'i', 'w', ' ', 'e', 't', 'i', 'h', 'w', ' ', 'a', ' ', 's', 'i',
	' ', 'f', 'l', 'a', 'd', 'n', 'a', 'G', ' ', 'r', 'e', 't', 's', 'a', 'M',
	0}},
{0}
};

int	test_ft_strrev(int *const ret)
{
	char	*str;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_strrev(g_test[i].str);
		result(g_test[i].num,
			str == g_test[i].str && !strcmp(str, g_test[i].expect));
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
