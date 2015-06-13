vector<string> generateParenthesis(int n) 
{
	vector<string> result;
	if (n == 0)
		return result;
	if (n == 1)
	{
		result.push_back("()");
		return result;
	}
	else
	{
		vector<string> last_result = generateParenthesis(n - 1);
		for (vector<string>::iterator it= last_result.begin(); it != last_result.end(); it++)
		{
			result.push_back("(" + *it + ")");
			result.push_back("()" + *it);
		}
		return result;
	}
}
 