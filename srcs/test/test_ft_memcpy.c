/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:07:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 07:14:47 by jodufour         ###   ########.fr       */
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
	uint8_t const	*src;
	uint8_t *const	dst0;
	uint8_t *const	dst1;
	size_t const	size;
	size_t const	n;
};

static t_test const		g_test[] = {
{1,
	(uint8_t[]){0x42, 0x21, 0x00},
	(uint8_t[]){0xff},
	(uint8_t[]){0xff},
	1, 0},
{2,
	(uint8_t[]){0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77},
	(uint8_t[]){0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88},
	(uint8_t[]){0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88},
	8, 8},
{3,
	(uint8_t[]){0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
	0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f},
	(uint8_t[]){0x01, 0x03, 0x05, 0x07, 0x09, 0x11, 0x13, 0x15, 0x17, 0x19,
	0x21, 0x23, 0x25, 0x27, 0x29, 0x31},
	(uint8_t[]){0x01, 0x03, 0x05, 0x07, 0x09, 0x11, 0x13, 0x15, 0x17, 0x19,
	0x21, 0x23, 0x25, 0x27, 0x29, 0x31},
	16, 10},
{4,
	(uint8_t[]){0x00, 0x03, 0x06, 0x09, 0x0c, 0x0f, 0x12, 0x15, 0x18, 0x1b,
	0x1e, 0x21, 0x24, 0x27, 0x2a, 0x2d, 0x30, 0x33, 0x36, 0x39, 0x3c, 0x3f,
	0x42, 0x45, 0x48, 0x4b, 0x4e, 0x51, 0x54, 0x57, 0x5a, 0x5d},
	(uint8_t[]){0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8, 0xf7, 0xf6,
	0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0, 0xef, 0xee, 0xed, 0xec, 0xeb, 0xea,
	0xe9, 0xe8, 0xe7, 0xe6, 0xe5, 0xe4, 0xe3, 0xe2, 0xe1, 0xe0},
	(uint8_t[]){0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8, 0xf7, 0xf6,
	0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0, 0xef, 0xee, 0xed, 0xec, 0xeb, 0xea,
	0xe9, 0xe8, 0xe7, 0xe6, 0xe5, 0xe4, 0xe3, 0xe2, 0xe1, 0xe0},
	32, 42},
{5,
	(uint8_t[]){0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
	0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
	0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21,
	0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d,
	0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
	0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f},
	(uint8_t[]){0x3f, 0x3e, 0x3d, 0x3c, 0x3b, 0x3a, 0x39, 0x38, 0x37, 0x36,
	0x35, 0x34, 0x33, 0x32, 0x31, 0x30, 0x2f, 0x2e, 0x2d, 0x2c, 0x2b, 0x2a,
	0x29, 0x28, 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20, 0x1f, 0x1e,
	0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12,
	0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08, 0x07, 0x06,
	0x05, 0x04, 0x03, 0x02, 0x01, 0x00},
	(uint8_t[]){0x3f, 0x3e, 0x3d, 0x3c, 0x3b, 0x3a, 0x39, 0x38, 0x37, 0x36,
	0x35, 0x34, 0x33, 0x32, 0x31, 0x30, 0x2f, 0x2e, 0x2d, 0x2c, 0x2b, 0x2a,
	0x29, 0x28, 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20, 0x1f, 0x1e,
	0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12,
	0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08, 0x07, 0x06,
	0x05, 0x04, 0x03, 0x02, 0x01, 0x00},
	64, 3},
{6,
	(uint8_t[]){0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
	0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
	0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21,
	0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d,
	0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
	0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45,
	0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51,
	0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d,
	0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
	0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75,
	0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f},
	(uint8_t[]){0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
	0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95,
	0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1,
	0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad,
	0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9,
	0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5,
	0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1,
	0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd,
	0xde, 0xdf, 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
	0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5,
	0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff},
	(uint8_t[]){0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
	0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95,
	0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1,
	0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad,
	0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9,
	0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5,
	0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1,
	0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd,
	0xde, 0xdf, 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
	0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5,
	0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff},
	128, 18},
{7,
	(uint8_t[]){0xff, 0x00, 0xfe, 0x01, 0xfd, 0x02, 0xfc, 0x03, 0xfb, 0x04,
	0xfa, 0x05, 0xf9, 0x06, 0xf8, 0x07, 0xf7, 0x08, 0xf6, 0x09, 0xf5, 0x0a,
	0xf4, 0x0b, 0xf3, 0x0c, 0xf2, 0x0d, 0xf1, 0x0e, 0xf0, 0x0f, 0xef, 0x10,
	0xee, 0x11, 0xed, 0x12, 0xec, 0x13, 0xeb, 0x14, 0xea, 0x15, 0xe9, 0x16,
	0xe8, 0x17, 0xe7, 0x18, 0xe6, 0x19, 0xe5, 0x1a, 0xe4, 0x1b, 0xe3, 0x1c,
	0xe2, 0x1d, 0xe1, 0x1e, 0xe0, 0x1f, 0xdf, 0x20, 0xde, 0x21, 0xdd, 0x22,
	0xdc, 0x23, 0xdb, 0x24, 0xda, 0x25, 0xd9, 0x26, 0xd8, 0x27, 0xd7, 0x28,
	0xd6, 0x29, 0xd5, 0x2a, 0xd4, 0x2b, 0xd3, 0x2c, 0xd2, 0x2d, 0xd1, 0x2e,
	0xd0, 0x2f, 0xcf, 0x30, 0xce, 0x31, 0xcd, 0x32, 0xcc, 0x33, 0xcb, 0x34,
	0xca, 0x35, 0xc9, 0x36, 0xc8, 0x37, 0xc7, 0x38, 0xc6, 0x39, 0xc5, 0x3a,
	0xc4, 0x3b, 0xc3, 0x3c, 0xc2, 0x3d, 0xc1, 0x3e, 0xc0, 0x3f, 0xbf, 0x40,
	0xbe, 0x41, 0xbd, 0x42, 0xbc, 0x43, 0xbb, 0x44, 0xba, 0x45, 0xb9, 0x46,
	0xb8, 0x47, 0xb7, 0x48, 0xb6, 0x49, 0xb5, 0x4a, 0xb4, 0x4b, 0xb3, 0x4c,
	0xb2, 0x4d, 0xb1, 0x4e, 0xb0, 0x4f, 0xaf, 0x50, 0xae, 0x51, 0xad, 0x52,
	0xac, 0x53, 0xab, 0x54, 0xaa, 0x55, 0xa9, 0x56, 0xa8, 0x57, 0xa7, 0x58,
	0xa6, 0x59, 0xa5, 0x5a, 0xa4, 0x5b, 0xa3, 0x5c, 0xa2, 0x5d, 0xa1, 0x5e,
	0xa0, 0x5f, 0x9f, 0x60, 0x9e, 0x61, 0x9d, 0x62, 0x9c, 0x63, 0x9b, 0x64,
	0x9a, 0x65, 0x99, 0x66, 0x98, 0x67, 0x97, 0x68, 0x96, 0x69, 0x95, 0x6a,
	0x94, 0x6b, 0x93, 0x6c, 0x92, 0x6d, 0x91, 0x6e, 0x90, 0x6f, 0x8f, 0x70,
	0x8e, 0x71, 0x8d, 0x72, 0x8c, 0x73, 0x8b, 0x74, 0x8a, 0x75, 0x89, 0x76,
	0x88, 0x77, 0x87, 0x78, 0x86, 0x79, 0x85, 0x7a, 0x84, 0x7b, 0x83, 0x7c,
	0x82, 0x7d, 0x81, 0x7e, 0x80, 0x7f},
	(uint8_t[]){0x7f, 0x80, 0x7e, 0x81, 0x7d, 0x82, 0x7c, 0x83, 0x7b, 0x84,
	0x7a, 0x85, 0x79, 0x86, 0x78, 0x87, 0x77, 0x88, 0x76, 0x89, 0x75, 0x8a,
	0x74, 0x8b, 0x73, 0x8c, 0x72, 0x8d, 0x71, 0x8e, 0x70, 0x8f, 0x6f, 0x90,
	0x6e, 0x91, 0x6d, 0x92, 0x6c, 0x93, 0x6b, 0x94, 0x6a, 0x95, 0x69, 0x96,
	0x68, 0x97, 0x67, 0x98, 0x66, 0x99, 0x65, 0x9a, 0x64, 0x9b, 0x63, 0x9c,
	0x62, 0x9d, 0x61, 0x9e, 0x60, 0x9f, 0x5f, 0xa0, 0x5e, 0xa1, 0x5d, 0xa2,
	0x5c, 0xa3, 0x5b, 0xa4, 0x5a, 0xa5, 0x59, 0xa6, 0x58, 0xa7, 0x57, 0xa8,
	0x56, 0xa9, 0x55, 0xaa, 0x54, 0xab, 0x53, 0xac, 0x52, 0xad, 0x51, 0xae,
	0x50, 0xaf, 0x4f, 0xb0, 0x4e, 0xb1, 0x4d, 0xb2, 0x4c, 0xb3, 0x4b, 0xb4,
	0x4a, 0xb5, 0x49, 0xb6, 0x48, 0xb7, 0x47, 0xb8, 0x46, 0xb9, 0x45, 0xba,
	0x44, 0xbb, 0x43, 0xbc, 0x42, 0xbd, 0x41, 0xbe, 0x40, 0xbf, 0x3f, 0xc0,
	0x3e, 0xc1, 0x3d, 0xc2, 0x3c, 0xc3, 0x3b, 0xc4, 0x3a, 0xc5, 0x39, 0xc6,
	0x38, 0xc7, 0x37, 0xc8, 0x36, 0xc9, 0x35, 0xca, 0x34, 0xcb, 0x33, 0xcc,
	0x32, 0xcd, 0x31, 0xce, 0x30, 0xcf, 0x2f, 0xd0, 0x2e, 0xd1, 0x2d, 0xd2,
	0x2c, 0xd3, 0x2b, 0xd4, 0x2a, 0xd5, 0x29, 0xd6, 0x28, 0xd7, 0x27, 0xd8,
	0x26, 0xd9, 0x25, 0xda, 0x24, 0xdb, 0x23, 0xdc, 0x22, 0xdd, 0x21, 0xde,
	0x20, 0xdf, 0x1f, 0xe0, 0x1e, 0xe1, 0x1d, 0xe2, 0x1c, 0xe3, 0x1b, 0xe4,
	0x1a, 0xe5, 0x19, 0xe6, 0x18, 0xe7, 0x17, 0xe8, 0x16, 0xe9, 0x15, 0xea,
	0x14, 0xeb, 0x13, 0xec, 0x12, 0xed, 0x11, 0xee, 0x10, 0xef, 0x0f, 0xf0,
	0x0e, 0xf1, 0x0d, 0xf2, 0x0c, 0xf3, 0x0b, 0xf4, 0x0a, 0xf5, 0x09, 0xf6,
	0x08, 0xf7, 0x07, 0xf8, 0x06, 0xf9, 0x05, 0xfa, 0x04, 0xfb, 0x03, 0xfc,
	0x02, 0xfd, 0x01, 0xfe, 00, 0xff},
	(uint8_t[]){0x7f, 0x80, 0x7e, 0x81, 0x7d, 0x82, 0x7c, 0x83, 0x7b, 0x84,
	0x7a, 0x85, 0x79, 0x86, 0x78, 0x87, 0x77, 0x88, 0x76, 0x89, 0x75, 0x8a,
	0x74, 0x8b, 0x73, 0x8c, 0x72, 0x8d, 0x71, 0x8e, 0x70, 0x8f, 0x6f, 0x90,
	0x6e, 0x91, 0x6d, 0x92, 0x6c, 0x93, 0x6b, 0x94, 0x6a, 0x95, 0x69, 0x96,
	0x68, 0x97, 0x67, 0x98, 0x66, 0x99, 0x65, 0x9a, 0x64, 0x9b, 0x63, 0x9c,
	0x62, 0x9d, 0x61, 0x9e, 0x60, 0x9f, 0x5f, 0xa0, 0x5e, 0xa1, 0x5d, 0xa2,
	0x5c, 0xa3, 0x5b, 0xa4, 0x5a, 0xa5, 0x59, 0xa6, 0x58, 0xa7, 0x57, 0xa8,
	0x56, 0xa9, 0x55, 0xaa, 0x54, 0xab, 0x53, 0xac, 0x52, 0xad, 0x51, 0xae,
	0x50, 0xaf, 0x4f, 0xb0, 0x4e, 0xb1, 0x4d, 0xb2, 0x4c, 0xb3, 0x4b, 0xb4,
	0x4a, 0xb5, 0x49, 0xb6, 0x48, 0xb7, 0x47, 0xb8, 0x46, 0xb9, 0x45, 0xba,
	0x44, 0xbb, 0x43, 0xbc, 0x42, 0xbd, 0x41, 0xbe, 0x40, 0xbf, 0x3f, 0xc0,
	0x3e, 0xc1, 0x3d, 0xc2, 0x3c, 0xc3, 0x3b, 0xc4, 0x3a, 0xc5, 0x39, 0xc6,
	0x38, 0xc7, 0x37, 0xc8, 0x36, 0xc9, 0x35, 0xca, 0x34, 0xcb, 0x33, 0xcc,
	0x32, 0xcd, 0x31, 0xce, 0x30, 0xcf, 0x2f, 0xd0, 0x2e, 0xd1, 0x2d, 0xd2,
	0x2c, 0xd3, 0x2b, 0xd4, 0x2a, 0xd5, 0x29, 0xd6, 0x28, 0xd7, 0x27, 0xd8,
	0x26, 0xd9, 0x25, 0xda, 0x24, 0xdb, 0x23, 0xdc, 0x22, 0xdd, 0x21, 0xde,
	0x20, 0xdf, 0x1f, 0xe0, 0x1e, 0xe1, 0x1d, 0xe2, 0x1c, 0xe3, 0x1b, 0xe4,
	0x1a, 0xe5, 0x19, 0xe6, 0x18, 0xe7, 0x17, 0xe8, 0x16, 0xe9, 0x15, 0xea,
	0x14, 0xeb, 0x13, 0xec, 0x12, 0xed, 0x11, 0xee, 0x10, 0xef, 0x0f, 0xf0,
	0x0e, 0xf1, 0x0d, 0xf2, 0x0c, 0xf3, 0x0b, 0xf4, 0x0a, 0xf5, 0x09, 0xf6,
	0x08, 0xf7, 0x07, 0xf8, 0x06, 0xf9, 0x05, 0xfa, 0x04, 0xfb, 0x03, 0xfc,
	0x02, 0xfd, 0x01, 0xfe, 00, 0xff},
	256, 100},
{0}
};

int	test_ft_memcpy(int *const ret)
{
	uint8_t	*addr0;
	uint8_t	*addr1;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		addr0 = memcpy(g_test[i].dst0, g_test[i].src, g_test[i].n);
		addr1 = ft_memcpy(g_test[i].dst1, g_test[i].src, g_test[i].n);
		result(g_test[i].num,
			(addr0 - g_test[i].dst0 == addr1 - g_test[i].dst1)
			&& !memcmp(g_test[i].dst0, g_test[i].dst1, g_test[i].size));
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
