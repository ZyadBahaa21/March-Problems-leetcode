class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		vector<int>ans;
		priority_queue<int, vector<int>, greater<int>>pr;
		for (auto it : nums)
			pr.push(it);
		while (!pr.empty())
		{
			ans.push_back(pr.top());
			pr.pop();
		}
		return ans;
	}
};