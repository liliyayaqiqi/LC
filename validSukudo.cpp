bool isValidSudoku(vector<vector<char>>& board)
{
	unordered_set<char> row[9];
	unordered_set<char> col[9];
	unordered_set<char> cell[3][3];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char n = board[i][j];
			int x = i/3;
			int y = j/3;
			if (isdigit(n) && (!row[i].insert(n).second || !col[j].insert(n).second || !cell[x][y].insert(n).second))
				return false;
		}
	}
	return true;
}