/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:00:23 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/20 23:25:42 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sorts_alg.h"

int		*merge(int *data, int f, int r)
{
	int	q;

	if (f < r)
	{
		q = (f + r) / 2;
		if (!merge(data, f, q))
			return (NULL);
		if (!merge(data, q + 1, r))
			return (NULL);
		return (merge_sort(data, f, q, r));
	}
	return (data);
}

// int main()
// {
// 	int		*arr;
// 	int		size;
// 	double	cpu_time_qs;
// 	clock_t	start;
// 	clock_t	end;

// 	srand(time(NULL));
// 	printf("Enter a size of array: \n");
// 	scanf("%d",&size);
// 	arr = malloc(size * sizeof(int));
// 	for (int i = 0; i < size; ++i)
// 		arr[i] = rand() % 100;
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr[%d]: %d\n", i, arr[i]);
// 	start = clock();
// 	merge(arr, 0, size - 1);
// 	end = clock();
// 	cpu_time_qs = (double)(end - start) / CLOCKS_PER_SEC;
// 	printf("merge sort time: %f\n", cpu_time_qs);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr[%d]: %d\n", i, arr[i]);
// 	free(arr);
// 	return (0);
// }