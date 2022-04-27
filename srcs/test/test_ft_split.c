/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:09:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:43:47 by jodufour         ###   ########.fr       */
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
	char const	c;
	char const	**expect;
};

static t_test const		g_test[] = {
{1,
	"",
	'Z',
	(char const *[]){
	NULL}},
{2,
	"Hello World !",
	' ',
	(char const *[]){
	"Hello",
	"World",
	"!",
	NULL}},
{3,
	"  Lerooooyyy       Jennnnkiiiiins    !!!      ",
	' ',
	(char const *[]){
	"Lerooooyyy",
	"Jennnnkiiiiins",
	"!!!",
	NULL}},
{4,
	"aaaaaaaaa",
	'a',
	(char const *[]){
	NULL}},
{5,
	">>_koala_forever_<<",
	'X',
	(char const *[]){
	">>_koala_forever_<<",
	NULL}},
{6,
	" f-o-r-t-y t-w-o ",
	'-',
	(char const *[]){
	" f",
	"o",
	"r",
	"t",
	"y t",
	"w",
	"o ",
	NULL}},
{7,
	"_GlOrY_ _tO_ _tHe_ _HoRdE_ _!_",
	'_',
	(char const *[]){
	"GlOrY",
	" ",
	"tO",
	" ",
	"tHe",
	" ",
	"HoRdE",
	" ",
	"!",
	NULL}},
{0}
};

int	test_ft_split(int *const ret)
{
	int			i;
	int			j;
	char		**tab;
	char const	**expect;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		tab = ft_split(g_test[i].str, g_test[i].c);
		if (!tab)
			return (*ret = FT_SPLIT_ERR);
		expect = g_test[i].expect;
		j = 0;
		while (tab[j] && expect[j] && !strcmp(tab[j], expect[j]))
			++j;
		result(g_test[i].num,
			!tab[j] && !expect[j]);
		free(tab);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
