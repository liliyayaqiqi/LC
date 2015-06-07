// precondition: the value for m or n is at most 100.
int record[100][100];
int uniquePaths(int m, int n) {

        for (int i = 0; i < m; i++)
        {
        	for (int j = 0; j < n; j++)
        	{
        		if (i == 0 || j == 0)
        			record[i][j] = 1;
        		else
        			 record[i][j] = 0;
        	}
        }
        	
        for (int i = 1; i < m; i++)
        {
        	for(int j = 1; j < n; j++)
        		record[i][j] = record[i-1][j] + record[i][j-1];
        }
        return record[m-1][n-1];
}