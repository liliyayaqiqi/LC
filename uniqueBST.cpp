/*
Use extra space to store the result that has already been
calculated in previous recursions.
*/
int calculateTreeNums(int begin, int end, int result[])
{
	int num_left = 0;
	int num_right = 0;
	int num_sum = 0;
	int number = end - begin + 1;
	if (number <= 1)
		return 1;
	if (result[number] > 0)
		return result[number];
	for (int i = begin; i <= end; i++)
	{
		num_left = calculateTreeNums(begin, i - 1, result);
		num_right = calculateTreeNums(i + 1, end, result);
		num_sum = num_sum + num_left * num_right;
	}
	result[number] = num_sum;
	return num_sum;
}
int numTrees(int n) {
	int* result = new int[n+1];
	for (int i = 0; i < n + 1; i++)
		result[i] = 0;
	int val = calculateTreeNums(1, n, result);
	delete[] result;
	return val;
}