/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcasecmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:09:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 05:10:22 by jodufour         ###   ########.fr       */
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
	int const	num;
	char const	*str0;
	char const	*str1;
};

static t_test const		g_test[] = {
{1,
	"",
	""},
{2,
	"abc",
	"abc"},
{3,
	"HELLO world",
	"hello WORLD"},
{4,
	"koala",
	"KO4L4"},
{5,
	"zelda power",
	"ZELDA_POWER_!!!"},
{6,
	"I wanne BE the VERY best ! LIKE no ONE ever WAS !",
	"i WANNA be THE very BEST . like NO one EVER was ."},
{7,
	"123456!@#",
	"1234567!@#"},
{0}
};

int	test_ft_strcasecmp(int *const ret)
{
	int	i;
	int	res0;
	int	res1;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		res0 = strcasecmp(g_test[i].str0, g_test[i].str1);
		res0 = !!res0 * (-(res0 < 0) | 1);
		res1 = ft_strcasecmp(g_test[i].str0, g_test[i].str1);
		res1 = !!res1 * (-(res1 < 0) | 1);
		result(g_test[i].num,
			res0 == res1);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
