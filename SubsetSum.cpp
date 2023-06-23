void solve(vector<int> nums, int i, int n, int s, vector<int>& v)
{
	if(i==n)
	{
		v.push_back(s);
		return;
	}
	solve(nums, i+1, n, s, v);
	solve(nums, i+1, n, s+nums[i], v);
}

vector<int> subsetSum(vector<int> &nums){
	// Write your code here.	
	int n=nums.size();
	vector<int> v;
	int s=0;
	solve(nums, 0, n, s, v);
	sort(v.begin(), v.end());
	return v;
}