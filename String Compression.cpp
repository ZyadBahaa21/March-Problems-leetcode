class Solution {
public:
	int compress(vector<char>& chars) {
		char ch;
		string ans = "";
		int cnt = 0;
		for (int i = 0; i < chars.size(); i++)
		{
			ch = chars[i];
			ans += ch;
			cnt++;
			for (int j = i + 1; j < chars.size(); j++)
			{
				if (chars[j] == ch)cnt++;
				else {
					i = j - 1;
					break;
				}
				if (j == chars.size() - 1)i = j;
			}
			if (cnt > 1)ans += to_string(cnt);
			cnt = 0;
		}
		chars.clear();
		for (int i = 0; i < ans.length(); i++)
			chars.push_back(ans[i]);
		return ans.size();
	}
};