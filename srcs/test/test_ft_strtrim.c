/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:21:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:45:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	*str;
	char const	*expect;
	char const	*set;
};

static t_test const		g_test[] = {
{1,
	"",
	"",
	""},
{2,
	"Only trimables",
	"",
	" abeilmnrstyO"},
{3,
	"No any trim possible",
	"No any trim possible",
	" \t\n"},
{4,
	"_-+>_<Only at the beginning<>__.",
	"Only at the beginning<>__.",
	"+<_-0>"},
{5,
	"Only at the end   ",
	"Only at the e",
	"n d"},
{6,
	"0123456789A9876543210",
	"A",
	"0918273645"},
{7,
	"_^o^/ >> SUCCESS << _^o^/",
	"SUCCESS",
	"  ^^__oo<<//>>"},
{0}
};

int	test_ft_strtrim(int *const ret)
{
	char const	*str;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_strtrim(g_test[i].str, g_test[i].set);
		if (!str)
			return (*ret = FT_STRTRIM_ERR);
		result(g_test[i].num,
			!strcmp(str, g_test[i].expect));
		free((void *)str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
