/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:31:22 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/29 18:57:50 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	queen_check(int x1, int y1, int x2, int y2)
{
	int diff;

	if (x1 == x2 || y1 == y2)
		return (-1);
	diff = x2 - x1;
	if (y1 + diff == y2 || y2 + diff == y1)
		return (-1);
	return (1);
}

int	board_check(int board[10], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (queen_check(i, board[i], n, board[n]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

void	ten_queens(int board[10], int i, int v)
{
	if (0 <= i && i < 10 && 0 <= v && v < 10)
		board[i] = v;
	if (i < 0)
		return ;
	if (i >= 10)
	{
		printf("%d %d %d %d %d %d %d %d %d %d\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8], board[9]);
		return(ten_queens(board, 9, board[9] + 1));
	}

	if (v >= 10)
	{
		board[i] = 0;
		return(ten_queens(board, i - 1, board[i - 1] + 1));
	}
	if (board_check(board, i) == -1)
		return(ten_queens(board, i, board[i] + 1));
	else
		return(ten_queens(board, i + 1, 0));
}

int main(void)
{
	int	board[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	ten_queens(board, 0, 0);
}