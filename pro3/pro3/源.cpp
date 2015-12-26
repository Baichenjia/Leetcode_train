#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
		int maxlen = 0;
		char visit[256];
		int i,j;
		for(i = 0;i < s.length();i++){
			memset(visit, 0, 256);
			visit[s[i]] = 1;
			for(j = i+1;j < s.length();j++){
				if(visit[s[j]] == 0)
					visit[s[j]] = 1;
				else{
					if(j - i > maxlen)
						maxlen = j-i;
					break;
				}
			}
			if((j == s.length()) && (j - i > maxlen))
				maxlen = j-i;
		}
		return maxlen;
    }

	int lengthOfLongestSubstring2(string s) {
		int *dp;
		dp = (int *)malloc(sizeof(int) * s.length());
		int i,j,maxlen = 1;
		int last_start = 0;
		if(s.length() == 0)
			return 0;
		dp[0] = 1;
		for(i = 1;i < s.length();i++)
		{
			for(j = i-1;j >= last_start;j--)
			{
				if(s[j] == s[i])
				{
					last_start = j+1;
					dp[i] = i-j;
					break;
				}
				else if(j == last_start)
					dp[i] = dp[i-1] + 1;
				else{}
			}
			if(dp[i] > maxlen)
				maxlen = dp[i];
		}
		return maxlen;
	}

	int lengthOfLongestSubstring(string s) {
		// for ASCII char sequence, use this as a hashmap
		vector<int> charIndex(256, -1);
		int longest = 0, m = 0;
		for (int i = 0; i < s.length(); i++) {
			m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
			charIndex[s[i]] = i;
			longest = max(longest, i - m + 1);
		}
	    return longest;
	}
};

int main()
{
	Solution su;
	string s = "c";
	int res = su.lengthOfLongestSubstring(s);
	cout<<res;

	getchar();getchar();
	return 0;
}