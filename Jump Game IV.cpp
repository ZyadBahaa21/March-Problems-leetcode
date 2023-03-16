class Solution {
public:
	int minJumps(vector<int>& arr) {
		int cnt = 0;
		map<int, vector<int>>mp;
		vector<int>vis(arr.size(), 0);
		queue<int>q;
		vis[0] = 1;
		for (int i = 0; i < arr.size(); i++) mp[arr[i]].push_back(i);
		q.push(0);
		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				int t = q.front(); q.pop();
				if (t == arr.size() - 1) return cnt;
				vector<int>temp = mp[arr[t]];
				if (t - 1 >= 0) temp.push_back(t - 1);
				if (t + 1 < arr.size()) temp.push_back(t + 1);
				for (auto it : temp) {
					if (!vis[it]) {
						q.push(it);
						vis[it] = 1;
					}
				}
				mp[arr[t]].clear();
			}
			cnt++;
		}
		return 0;
	}
};