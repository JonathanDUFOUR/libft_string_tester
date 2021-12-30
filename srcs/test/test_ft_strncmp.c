/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:17:58 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 13:29:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "lorem_ipsum.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*str0;
	char const		*str1;
	size_t const	n;
};

static t_test const		g_test[] = {
{1,
	"",
	"",
	0},
{2,
	"not",
	"the same",
	0},
{3,
	"Abcdefghij",
	"Abcdefghij",
	50},
{4,
	"Hello everyone",
	"Hello everyone!",
	14},
{5,
	LOREM_512 "@",
	LOREM_512 "#",
	512},
{6,
	LOREM_2048 "42",
	LOREM_2048 "43",
	2048},
{7,
	LOREM_65536 "AA",
	LOREM_65536 "AB",
	65537},
{0}
};

int	test_ft_strncmp(int *const ret)
{
	int	i;
	int	res0;
	int	res1;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		res0 = strncmp(g_test[i].str0, g_test[i].str1, g_test[i].n);
		res0 = !!res0 * (-(res0 < 0) | 1);
		res1 = ft_strncmp(g_test[i].str0, g_test[i].str1, g_test[i].n);
		res1 = !!res1 * (-(res1 < 0) | 1);
		result(g_test[i].num,
			res0 == res1);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
