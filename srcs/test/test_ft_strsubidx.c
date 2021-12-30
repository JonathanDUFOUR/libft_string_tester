/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strsubidx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:20:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 16:10:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*str;
	char const		*expect;
	size_t const	idx;
};

static t_test const		g_test[] = {
{1,
	"",
	"",
	0},
{2,
	"A",
	"",
	0},
{3,
	"Baobab",
	"Baoab",
	3},
{4,
	"No `idx` in string !",
	"No `idx` in string !",
	42},
{5,
	"`idx` at the first place",
	"idx` at the first place",
	0},
{6,
	"This time, it is at the last place !",
	"This time, it is at the last place ",
	35},
{7,
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
	"ABCDEFGHIJKLMNPQRSTUVWXYZ",
	14},
{0}
};

int	test_ft_strsubidx(int *const ret)
{
	char const	*str;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_strsubidx(g_test[i].str, g_test[i].idx);
		if (!str)
			return (FT_STRSUBCHR_ERR);
		result(g_test[i].num,
			!strcmp(str, g_test[i].expect));
		free((void *)str);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
