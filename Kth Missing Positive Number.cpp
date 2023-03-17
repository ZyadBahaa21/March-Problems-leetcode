class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		vector<int>v;
		map<int, int>mp;
		for (int i = 0; i < arr.size(); i++)
			mp[arr[i]]++;
		for (int i = 1; i <= arr[arr.size() - 1] + k; i++)
		{
			if (mp.find(i) == mp.end())
				v.push_back(i);
		}
		return v[k - 1];
	}
};