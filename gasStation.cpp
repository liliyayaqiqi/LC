/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.
 Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 Note:
 The solution is guaranteed to be unique. 
*/
//the start point is the first station that guarantees the sum of the sequence to the last staion (if not circular)
 // is non-negative
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	if (gas.empty() || cost.empty() || gas.size() != cost.size())
		return -1;
	int total = 0;
	int sum = 0;
	int start = 0;
	for (int i = 0; i < gas.size(); i++)
	{
		total += gas[i] - cost[i];
		if (sum < 0)
		{
			sum = 0;
			start = i;
		}
		sum += gas[i] - cost[i];
	}
	return total < 0? -1: start;
}