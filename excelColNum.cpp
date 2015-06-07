int titleToNumber(string s) {
	int num = 0;
	for (string::iterator it = s.begin(); it < s.end(); it++)
	{
		int converted = *it - 'A' + 1;
		num = num*26 + converted;
	}
	return num;
}