//You may not slant the container
int maxArea(vector<int>& height)
{
	int i = 0, j = height.size() - 1, max_area = 0;
	while(i < j)
	{
		max_area = max(min(height[i], height[j]) * (j - i), max_area);
		height[i] > height[j]? j-- : i++;
	}
	return max_area;
}