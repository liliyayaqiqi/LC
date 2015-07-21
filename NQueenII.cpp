/*
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
*/

void NQueens(int n, int row, vector<int>& board, int& cnt)
{
	if (row >= n)
		cnt++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			bool judge = true;
			for (; j < row; j++)
			{
				if (board[j] == i || abs(board[j] - i) == row - j)
				{
					judge = false;
					break;
				}
			}
			if (judge)
			{
				board[row] = i;
				NQueens(n, row+1, board);
			}
		}
	}
}

int totalNQueens(int n)
{
	vector<int> board(n, 0);
	int cnt = 0;
	NQueens(n, 0, board, cnt);
	return cnt;
}