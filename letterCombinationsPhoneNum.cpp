void findAllCombinations(vector<string>& result, vector<string>& map, string solution, string digits, int curNum)
{
	if (curNum == digits.length())
	{
		result.push_back(solution);
		return;
	}
	int index = digits[curNum] - '2';
	for (int i = 0; i < map[index].length(); i++)
		findAllCombinations(result, map, solution + map[index][i], digits, curNum + 1);
}
vector<string> letterCombinations(string digits)
{
	vector<string> result;
	if (digits.length() == 0)
		return result;
	string solution("");
	vector<string> map;
	map.push_back("abc");
	map.push_back("def");
	map.push_back("ghi");
	map.push_back("jkl");
	map.push_back("mno");
	map.push_back("pqrs");
	map.push_back("tuv");
	map.push_back("wxyz");
	findAllCombinations(result, map, solution, digits, 0);
	return result;
}