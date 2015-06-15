/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

bool isValid(string s)
{
	vector<char> stack1;
	vector<char> stack2;
	for(string::iterator it = s.begin(); it != s.end(); it++)
		stack1.push_back(*it);
	while(!stack1.empty())
	{
		char cp = stack1.back();
		stack1.pop_back();
		if (cp == ')' || cp == ']' || cp == '}')
			stack2.push_back(cp);
		else
		{
			if (stack2.empty())
				return false;
			char cp2 = stack2.back();
			stack2.pop_back();
			if (cp == '(' && cp2 != ')')
				return false;
			if (cp == '[' && cp2 != ']')
				return false;
			if (cp == '{' && cp2 != '}')
				return false;
		}
	}
	if (!stack2.empty())
		return false;
	return true;
}