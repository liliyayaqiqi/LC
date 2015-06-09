<<<<<<< HEAD
bool containsDuplicate(vector<int>& nums) {
	std::map<int, int> container;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		if (container.find(*it) != container.end())
			return true;
		else
			container[*it] = 0;
	}
	return false;
=======
bool containsDuplicate(vector<int>& nums) {
	std::map<int, int> container;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		if (container.find(*it) != container.end())
			return true;
		else
			container[*it] = 0;
	}
	return false;
>>>>>>> 87b75386303b622fbe386c6ffdfa4ffe0e201c52
}