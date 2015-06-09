/* The following solution gives the right answer but cannot pass the online judgement
due to the order of the parenthesis string.
*/
/*vector<string> generateParenthesis(int n) 
{
	vector<string> result;
	if (n == 0)
		return result;
	if (n == 1)
	{
		result.push_back("()");
		return result;
	}
	string allParenthesis = "";
	for (int i = 0; i < n - 1; i++)
		allParenthesis += "()";
	vector<string> last_result = generateParenthesis(n - 1);
	for (vector<string>::iterator it = last_result.begin(); it != last_result.end(); it++)
	{
		if (*it == allParenthesis)
		{
			result.push_back("(" + *it + ")");
			result.push_back("()" + *it);
		}
		else
		{
			result.push_back("(" + *it + ")");
			result.push_back("()" + *it);
			result.push_back(*it + "()");
		}
	}
	return result;
 }*/

void findAnswers(int left, int right, string cur, vector<string>& vect)
{
	if (left == 0 && right == 0)
	{
		vect.push_back(cur);
		return;
	}
	if (left > 0)
		findAnswers(left - 1, right, cur + "(" + vect);
	if (right > left && right != 0)
		findAnswers(left, right - 1, cur + ")" + vect);
}

vector<string> generateParenthesis(int n) 
{
	vector<string> result;
	string cur = "";
	findAnswers(n, n, cur, result);
	return result;
}