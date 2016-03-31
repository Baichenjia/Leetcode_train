#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		int n = s.size();
		if(n == 0 || n == 1)  return 0;
		vector<vector<int>> dp(n, vector<int>(n));
		for(int i = 0;i < n;i ++)
			dp[i][i] = 0;
		for(int l = 1;l < n;l++){
			for(int i = 0;i < n-l;i++){
				int j = l + i;
				int len = ispare(s.substr(i, j+1));
				//cout<<i<<", "<<j<<"  :"<<len<<endl;
				if(len > 0){
					dp[i][j] = len;
					break;
				}
				else{
					dp[i][j] = dp[i+1][j] > dp[i][j-1]?dp[i+1][j]: dp[i][j-1];
				}
			}
		}
		return dp[0][n-1];
    }

	int ispare(string s){
		int res = 0;
		if(s.size() % 2 == 1)  return 0;
		for(int i = 0;i < s.size();i++){
			if(s[i] == '(')
				res += 1;
			else
				res += -1;
			if(res < 0)  return 0;
		}
		if(res == 0) return s.size();
		else return 0;
	}

};


int main(){
	Solution sul;
	string s = "())()()(())((()(()()(((()))((((())((()(())()())(()((((()))()(()))(())()(())(()(((((())((((((()())())(()(()((())()))(()))))))()(()))((((())()()()))()()()(((()(()())(()()(()(()()(((()))))))()()))())())((()()))))))((()))(((()((())()(()()))((())))()()())))))))()))))(()))))()))()))()((())))((()))(()))))))(((()))))))))()(()()()(())((())()))()()(())))()()))(()())()))(((()())()))((())((((()))(()(()(()()()(((())()(((((()))((()(((((())(()()))((((((((()(()(()(()(())))(())(()())())(()((((()(())((()(())))(())))()(((((()(()()(())))))))())(())(())(()()(((())))((()))(((((()))))())))()((()))()))))())))))((())(((((()()))((((())))(((()(()(())())(((()(()(()()()())))())()))((()((())())()()()(((())(((((()((((((()((()())))((((())((()(((((((()(()((()()()(()(()())(()(()()((((())))()(((()())))(()()))()(()()()()(((((())(()))))((()))())))()((((((()))())))()(()))(())))((((()())(((((()()())(((((())(()())(()))))()(()()))()))))))())))(((())(()(()()))(()))()(((())))())((((()(((()))))))()(()(()))()()(()()))))))))((()))))))(())((()((()))()))((((((()())))))(()((())((((()))))(()(()()()()(()))()()(()(()))(()()(((((((()())(())(()())((())())()(()())((())()())())(()())))())))(())())())(())((()())(((()()))()))()()))()(()(())((((((((())))()((())((()((((((((((()))))(()(((((())(()(()())())))((())())))))()))(()((()()))((()((())()()()((()(())())((())())(()()(((())))))())()()(()))()())(()(()((())))((((()()(())))())(())(()(()(())())())(()()())()(())())))(()()(((())))((()()(((())()()(()())((((()()(()())(()((((()(()()(()(()(((()((()())(()()))(()((((()(((((()))))()()))(((()((((((()(()()()()())()))(()(())))))((()(((()())())))(((()()))(()(()(((((((()()))(()(())))())()(())())(())(()))(())(()))()()(()()())))))()))()((())(((()((((((((())()()))())))((()())(";
	int res = sul.longestValidParentheses(s);
	cout<<res<<endl;
	getchar();getchar();
	return 0;
}