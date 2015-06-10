void backtracking(int index, int k, int n, vector<int>& curRes, vector<vector<int>>& result)
{
    if (curRes.size() == k)
    {
        result.push_back(curRes);
        return;
    }
    for(int i = index; i <= n; i++)
    {
        curRes.push_back(i);
        backtracking(++index, k, n, curRes, result);
        curRes.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> result;
    vector<int> curRes;
    int index = 1;
    backtracking(index, k, n, curRes, result);
    return result;
}
