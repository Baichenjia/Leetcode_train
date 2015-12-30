#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
		string* str = new string[numRows]; 
		if(numRows == 1)
			return s;
		int count = 0;
		int last_change = 0;
		bool flag = true;
		for(int i = 0;i < n;i++){
			str[count] += s[i];
			if(i - last_change == numRows-1){
				last_change = i;
				flag = !flag;
			}
			if(flag)
				count++;
			else
				count--;
		}
		string res;
		for(int i = 0;i < numRows;i++)
			res = res + str[i];
		return res;
    }
};

int main(){
	Solution sul;
	string s = "AB";
	int rows = 1;
	string res = sul.convert(s, rows);
	cout<<res<<endl;

	getchar();getchar();
	return 0;
}








