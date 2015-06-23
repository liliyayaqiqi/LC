/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
*/
bool isIsomorphic(string s, string t)
{
	if (s.length() != t.length())
		return false;
	if (s.length() == 0)
		return true;
	bool result = true;
	unordered_map<char, char> map1;
	unordered_map<char, char> map2;
	for (int i = 0; i < s.length(); i++)
	{
		unordered_map<char, char>::iterator it1 = map1.find(s[i]);
		unordered_map<char, char>::iterator it2 = map2.find(t[i]);
		if (it1 == map1.end() && it2 == map2.end())
		{
			map1[s[i]] = t[i];
			map2[t[i]] = s[i];
		}
		else
		{
			if (it1 != map1.end() && it2 != map2.end() && it1->second == t[i] && it2->second == s[i])
				continue;
			else 
				return false;
		}
	}
	return result;
}
// The abover solution uses stl unordered_map and is relatively slow
// do not use hash_map
bool isIsomorphic(string s, string t)
{
	if (s.length() != t.length())
		return false;
	if (s.length() == 0)
		return true;
	vector<int> map1(128, -1);
	vector<int> map2(128, -1);
	for (int i = 0; i < s.length() ; i++)
	{
		if (map1[s[i]] == map2[t[i]])
		{
			if (map1[s[i]] == -1)
			{
				map1[s[i]] = i;
				map2[t[i]] = i;
			}
		}
		else
			return false;
	}
	return true;
}
