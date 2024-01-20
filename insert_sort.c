/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:51:47 by blackrider        #+#    #+#             */
/*   Updated: 2024/01/20 23:49:14 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	*insert_sort(int *data, int f, int r)
{
	int	i;
	int	j;
	int	key;

	if (f < 0 || f > r)
		return (NULL);
	i = f + 1;
	while (i <= r)
	{
		key = data[i];
		j = i - 1;
		while (j >= f && data[j] > key)
		{
			data[j + 1] = data[j];
			--j;
		}
		data[j + 1] = key;
		++i;
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
// 		arr[i] = rand() % 1000;
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr[%d]: %d\n", i, arr[i]);
// 	start = clock();
// 	insert_sort(arr, 0, size - 1);
// 	end = clock();
// 	cpu_time_qs = (double)(end - start) / CLOCKS_PER_SEC;
// 	printf("insert sort time: %f\n", cpu_time_qs);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("arr[%d]: %d\n", i, arr[i]);
// 	free(arr);
// 	return (0);
// }
