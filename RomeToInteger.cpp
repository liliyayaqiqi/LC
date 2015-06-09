/*if current number is smaller than the last number, add the current number to sum;
if current number is larger than the last number, subtract twice the last number
and add the current number to sum.
*/
int romanToInt(string s) {
	map<char, int> romeMap;
	romeMap['I'] = 1;
	romeMap['V'] = 5;
	romeMap['X'] = 10;
	romeMap['L'] = 50;
	romeMap['C'] = 100;
	romeMap['D'] = 500;
	romeMap['M'] = 1000;
	int sum = 0;
	int last_num = 0;
	string::iterator it = s.begin();
	for(; it != s.end(); it++)
	{
		int num = romeMap[*it];
		if (num > last_num)
		{
			sum -= 2*last_num;
			sum += num;
		}
		else
			sum += num;
		last_num = num;
	}
	return sum;
}