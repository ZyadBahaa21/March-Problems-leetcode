class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		sort(piles.begin(), piles.end());
		long long Hrs, left = 1, right = piles[piles.size() - 1], ans = INT_MAX;;
		while (left <= right) {
			Hrs = 0;
			int mid = (left + right) / 2;
			for (int i = 0; i < piles.size(); i++) {
				if (piles[i] % mid == 0)
					Hrs += piles[i] / mid;
				else
					Hrs += (piles[i] / mid) + 1;
			}
			if (Hrs <= h) {
				ans = mid;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		return ans;
	}
};