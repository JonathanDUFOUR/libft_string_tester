/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:21:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 16:44:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "lorem_ipsum.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*str;
	char const		*expect;
	size_t const	start;
	size_t const	len;
};

static t_test const		g_test[] = {
{1,
	"",
	"",
	0,
	0},
{2,
	"abc",
	"a",
	0,
	1},
{3,
	"koala",
	"ala",
	2,
	3},
{4,
	"Hello WOrld !",
	"Orl",
	7,
	3},
{5,
	"Gimme gimme gimme a man after midnight !",
	"man after",
	20,
	9},
{6,
	"Un elephant qui se balancait sur une toile toile toile, toile d'araignee",
	"ile, to",
	51,
	7},
{7,
	LOREM_65536,
	&LOREM_65536[32768],
	32768,
	32768},
{0}
};

int	test_ft_substr(int *const ret)
{
	char const	*str;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_substr(g_test[i].str, g_test[i].start, g_test[i].len);
		if (!str)
			return (*ret = FT_SUBSTR_ERR);
		result(g_test[i].num,
			!strcmp(str, g_test[i].expect));
		free((void *)str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
