class Solution {
public:
	long long countSubarrays(vector<int>& nums, int minK, int maxK) {
		long long count = 0, lastMin = -1, lastMax = -1, leftBound = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= minK && nums[i] <= maxK) {
				lastMin = (nums[i] == minK) ? i : lastMin;
				lastMax = (nums[i] == maxK) ? i : lastMax;
				count += max(0, int(min(lastMin, lastMax) - leftBound));
			}
			else {
				leftBound = i;
				lastMin = -1;
				lastMax = -1;
			}
		}
		return count;
	}
};