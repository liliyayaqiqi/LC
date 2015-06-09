string intToRoman(int num) {
	int val[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int str[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	string result("");
	while (i < 13)
	{
		while (num - val[i] > 0)
		{
			result += str[i];
			num -= val[i];
		}
		i++;
	}
	return result;  
}