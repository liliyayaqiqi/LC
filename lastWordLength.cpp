/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.
*/
int lengthOfLastWord(string s)
{
	int index = s.length() - 1;
	int cnt = 0;
	while (index >= 0 && s[index] == ' ')
		index--;
	while (index >= 0 && s[index] != ' ')
	{
		index--;
		cnt++;
	}
	return cnt;
}