#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome2(string s) {
		int n = s.length();
		string res = "";
		if(s.length() == 0){
			res = "";
			return res;
		}
		else if(s.length() == 1){
			res = s;
			return res;
		}
		else{}
		int p1,p2,l1,l2;
		for(int i = 1;i < n;i++){
			string res1 = "",res2 = "";
			if(s[i-1] == s[i]){
				p1 = i-1;
				p2 = i;
				while(s[p1] == s[p2]){
					p1 --;
					p2 ++;
					if(p1 < 0)
						break;
				}
				res1 = s.substr(p1+1,p2-p1-1);
			}
			if(s[i-1] == s[i+1]){
				l1 = i-1;
				l2 = i+1;
				while(s[l1] == s[l2]){
					l1--;
					l2++;
					if(l1 < 0)
						break;
				}
				res2 = s.substr(l1+1,l2-l1-1);
			}
			string res3 = res1.length()>res2.length()?res1:res2;
			res = res.length()>res3.length()?res:res3;
		}
		return res;
    }

	//http://blog.csdn.net/feliciafay/article/details/16984031 动态规划解法
    string longestPalindrome(string s) {
		bool flag[1000][1000] = {false};
		int maxlen = 0;
		string maxstring;
		if(s.length() == 1)
			maxstring = s;
		for(int i = 0;i < s.length();i++)
			flag[i][i] = true;
		for(int i = 0;i < s.length()-1;i++){
			if(s[i] == s[i+1]){
				flag[i][i+1] = true;
				if(maxlen < 2){
					maxlen = 2;
					maxstring = s.substr(i, 2);
				}
			}
		}
		for(int i = 3;i <= s.length();i++){  //对角线
			for(int j = 0;j <= s.length()-i;j++){   //横坐标
				int k = j + i - 1;   //纵坐标
				if(s[j] == s[k]){
					flag[j][k] = flag[j+1][k-1];
					if(flag[j][k] == true){
						if(k - j + 1 > maxlen){
							maxlen = k-j+1;
							maxstring = s.substr(j, k-j+1);
						}
					}
				}
			}
		}
		return maxstring;
	}

	//*****************************
	
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};

int main(){
	Solution sul;
	string str = "a";
	string res = sul.longestPalindrome2(str);
	cout<<res<<endl;

	getchar();getchar();
	return 0;
}