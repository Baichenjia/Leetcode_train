#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
		int num = 0;
		int minlength = 9999;
		if(strs.size() == 0)
		    return res;
		for(int i = 0;i < strs.size();i++){
			if(minlength > strs[i].length())
				minlength = strs[i].length();  //最小长度
		}
		char c; bool flag;
		for(int i = 0;i < minlength;i++){
			c = strs[0][i];
			flag = true;
			for(int j = 0;j < strs.size();j++){
				if(strs[j][i] != c){
					flag = false;
					break;
				}
			}
			if(!flag)
				break;
			else
				res += c;
		}
		return res;
    }

	string longestCommonPrefix1(vector<string>& strs) {
        string prefix = "";
        for(int idx=0;strs.size()>0; prefix+=strs[0][idx], idx++)
            for(int i=0; i<strs.size(); i++)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
        return prefix;
	}
};

int main()
{
	Solution sul;
	vector<string> strs;
	strs.push_back("aca");
	strs.push_back("cba");
	string res = sul.longestCommonPrefix(strs);
	cout<<res<<endl;
	getchar();getchar();
	return 0;
}