/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:11:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 10:34:45 by jodufour         ###   ########.fr       */
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
	"tutu",
	"tata"},
{3,
	"koala",
	"koala king"},
{4,
	"+[#pokemon#]+",
	"+[#POKEMON#]+"},
{5,
	"we are the same",
	"we are the same"},
{6,
	"alpha bravo Charlie delta",
	"alpha bravo charlie delta"},
{7,
	"BlIzzaRD_UbisofT-AnKAma+aCTiVisiON",
	"BlIzzaRD_UbisofT+AnKAma-aCTiVisiON"},
{0}
};

int	test_ft_strcmp(int *const ret)
{
	int	res0;
	int	res1;
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		res0 = strcmp(g_test[i].str0, g_test[i].str1);
		res0 = !!res0 * (-(res0 < 0) | 1);
		res1 = ft_strcmp(g_test[i].str0, g_test[i].str1);
		res1 = !!res1 * (-(res1 < 0) | 1);
		result(g_test[i].num,
			res0 == res1);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
