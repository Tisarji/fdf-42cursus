/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:31:24 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/04 02:54:42 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*calloc;

	calloc = malloc (size * count);
	if (!calloc)
		return (0);
	count = size * count;
	size = 0;
	while (size < count)
	{
		((char *)calloc)[size] = 0;
		size++;
	}
	return (calloc);
}

// int	main(void)
// {
// 	size_t *a;
// 	size_t *b;
// 	size_t	n = INT_MIN;
// 	printf("SIZE_MAX\t= %d\nThen size_t\t= %zu\n", SIZE_MAX, (size_t)SIZE_MAX);
// 	printf("INT_MIN\t\t= %d\nThen size_t\t= %zu\n", INT_MIN, (size_t)INT_MIN);
// 	// printf("SIZE_MAX - INT_MIN = %zu\n", (size_t)(SIZE_MAX - INT_MIN));
// 	// printf("INT_MIN - SIZE_MAX = %zu\n", (size_t)(INT_MIN - SIZE_MAX));
// 	// a = ft_calloc(-5, -5);
// 	// a = calloc(-5,-5);
// 	// a = ft_calloc(-1, -1);
// 	// a = ft_calloc(1, -1);
// 	// a = ft_calloc(-1, 1);
// 	// a = ft_calloc(n, n);
// 	// a = ft_calloc(n, 1);
// 	a = ft_calloc(1, n);
// 	// a = calloc(-1,-1); 
// 	// a = calloc(1,-1);
// 	b = calloc(n,n);
// 	// printf("%zu %p\n", n, a);
// 	printf("%zu %p %p\n", n, a, b);
// 	free(a);
// 	// free(b);
// 	return (0);
// }
