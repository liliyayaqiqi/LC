bool isHappy(int n)
{
	vector<int> temp;
	while(true)
	{
		int sum = 0;
		while (n)
		{
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		if (sum == 1)
			return true;
		if(!temp.empty())
		{
			for(vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
			{
				if(*it == sum)
					return false;
			}
		}
		temp.push_back(sum);
		n = sum;
	}
}