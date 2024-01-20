/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:06:51 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/21 00:32:20 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sorts_alg.h"

int		*merge_insert(int *data, int f, int r)
{
	int	q;
    if (r - f < MAX_INS)
        return (insert_sort(data, f, r));
    q = (f + r) / 2;
    if (!merge_insert(data, f, q))
        return (NULL);
    if (!merge_insert(data, q + 1, r))
        return (NULL);
    return (merge_sort(data, f, q, r));
}

int main()
{
	int		*arr_m;
    int     *arr_mi;
    int     *arr_q;
    int     *arr_qi;
    double	cpu_time_mi;
    double  cpu_time_m;
    double  cpu_time_q;
    double  cpu_time_qi;
	int		size;
	clock_t	start;
	clock_t	end;

	srand(time(NULL));
	printf("Enter a size of array: \n");
	scanf("%d",&size);
	arr_m = malloc(size * sizeof(int));
    arr_mi = malloc(size * sizeof(int));
    arr_q = malloc(size * sizeof(int));
    arr_qi = malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i)
    {
		arr_m[i] = rand() % 1000000000;
        arr_mi[i] = arr_m[i];
        arr_q[i] = arr_m[i];
        arr_qi[i] = arr_m[i];
    }
	// for (int i = 0; i < size; ++i)
	// 	printf("arr_m[%d]: %d\tarr_mi[%d]: %d\tarr_q[%d]: %d\tarr_qi[%d], %d\n", i, arr_m[i], i, arr_mi[i], i, arr_q[i], i, arr_qi[i]);
    start = clock();
	quick_sort_insert(arr_qi, 0, size - 1);
	end = clock();
	cpu_time_qi = (double)(end - start) / CLOCKS_PER_SEC;
    start = clock();
	quick_sort(arr_q, 0, size - 1);
	end = clock();
	cpu_time_q = (double)(end - start) / CLOCKS_PER_SEC;
    start = clock();
	merge(arr_m, 0, size - 1);
	end = clock();
	cpu_time_m = (double)(end - start) / CLOCKS_PER_SEC;
	start = clock();
	merge_insert(arr_mi, 0, size - 1);
	end = clock();
	cpu_time_mi = (double)(end - start) / CLOCKS_PER_SEC;
	printf("insert act. num: %d\tmerge sort: %f\tmerge_insert sort: %f\tdiv: %f\tquick s.: %f\tquick_insert s.: %f\n",
     MAX_INS, cpu_time_m, cpu_time_mi, cpu_time_m - cpu_time_mi, cpu_time_q, cpu_time_qi);
	// for (int i = 0; i < size; ++i)
	// 	printf("arr_m[%d]: %d\tarr_mi[%d]: %d\tarr_q[%d]: %d\tarr_qi[%d], %d\n", i, arr_m[i], i, arr_mi[i], i, arr_q[i], i, arr_qi[i]);
	free(arr_mi);
    free(arr_m);
    free(arr_q);
    free(arr_qi);
	return (0);
}
