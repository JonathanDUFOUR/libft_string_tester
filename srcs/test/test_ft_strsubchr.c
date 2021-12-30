/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strsubchr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:20:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 15:29:38 by jodufour         ###   ########.fr       */
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
	int const	num;
	char const	*str;
	char const	*expect;
	char const	c;
};

static t_test const		g_test[] = {
{1,
	"",
	"",
	0},
{2,
	"A",
	"",
	'A'},
{3,
	"Baobab",
	"Baoab",
	'b'},
{4,
	"No `c` in string !",
	"No `c` in string !",
	'X'},
{5,
	"A char `c` at the first place",
	" char `c` at the first place",
	'A'},
{6,
	"This time, it is at the last place !",
	"This time, it is at the last place ",
	'!'},
{7,
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
	"ABCDEFGHIJKLMNPQRSTUVWXYZ",
	'O'},
{0}
};

int	test_ft_strsubchr(int *const ret)
{
	char const	*str;
	int			i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str = ft_strsubchr(g_test[i].str, g_test[i].c);
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
