/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:41:58 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/21 00:24:10 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sorts_alg.h"

void	swap(int *data, int i, int j)
{
	int	tmp;

	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

int		partition(int *data, int star, int end)
{
	int	x;
	int	i;
	int	j;

	x = data[end];
	i = star - 1;
	j = star;
	while (j < end)
	{
		if (data[j] <= x)
		{
			++i;
			swap(data, i, j);
		}
		++j;
	}
	++i;
	swap(data, i, end);
	return (i);
}

int		rand_part(int *data, int star, int end)
{
	swap(data, rand() % end, end);
	return (partition(data, star, end));
}

void	quick_sort(int *data, int f, int r)
{
	int	q;

	if (f < r)
	{
		q = partition(data, f, r);
		quick_sort(data, f, q - 1);
		quick_sort(data, q + 1, r);
	}
}

int		*quick_sort_insert(int *data, int f, int r)
{
	int	q;

    if (r - f < MAX_INS)
        return (insert_sort(data, f, r));
	q = rand_part(data, f, r);
	quick_sort(data, f, q - 1);
	quick_sort(data, q + 1, r);
	return (data);
}

void	quick_sort_rand(int *data, int f, int r)
{
	int	q;

	if (f < r)
	{
		q = rand_part(data, f, r);
		quick_sort(data, f, q - 1);
		quick_sort(data, q + 1, r);
	}
}


// int main()
// {
// 	int		*data;
// 	int		*arr_r;
// 	int		size;
// 	int		j;
// 	double	cpu_time_rqs;
// 	double	cpu_time_qs;
// 	clock_t	start;
// 	clock_t	end;

// 	srand(time(NULL));
// 	printf("Enter a size of array: \n");
// 	scanf("%d",&size);
// 	data = malloc(size * sizeof(int));
// 	arr_r = malloc(size * sizeof(int));
// 	for (int i = 0; i < size; ++i)
// 	{
// 		data[i] = rand() % 10000;
// 		arr_r[i] = data[i];
// 	}
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("data[%d]: %d\n", i, data[i]);
// 	start = clock();
// 	quick_sort(data, 0, size - 1);
// 	end = clock();
// 	cpu_time_qs = (double)(end - start) / CLOCKS_PER_SEC;
// 	start = clock();
// 	quick_sort_rand(arr_r, 0, size - 1);
// 	end = clock();
// 	cpu_time_rqs = (double)(end - start) / CLOCKS_PER_SEC;
// 	printf("quick sort time: %f\trandom qs time: %f\n", cpu_time_qs, cpu_time_rqs);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("data[%d]: %d\n", i, data[i]);
// 	return (0);
// }