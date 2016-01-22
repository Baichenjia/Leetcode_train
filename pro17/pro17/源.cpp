#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		string str[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> res;
		res.push_back("");
		vector<string> newres;
		for(int i = 0;i < digits.length();i++)
		{
			newres.clear();
			for(int j = 0;j < str[digits[i]-'0'].length();j++)
			{
				char c = str[digits[i]-'0'][j];
				for(int k = 0;k < res.size();k++)
				{
					newres.push_back(res[k] + c);
				}
			}
			res = newres;
		}
		return res;
	}
};

int main()
{
	Solution sul;
	string str = "234";
	vector<string> liststr = sul.letterCombinations(str);
	for(int i = 0;i < liststr.size();i++)
		cout<<liststr[i]<<endl;
	getchar();getchar();
	return 0;
}