#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
		if(s.empty())
			return 0;
		string::iterator it = s.end()-1;
		while(it != s.begin() && *it == ' ') it--;
		int count = 0; 
		while(it != s.begin() && *it != ' '){
			count++;
			it--;
		}
		if(*it == ' ')
			return count;
		else
			return count+1;
    }
};

int main(){
	string s = "  i am a student ";
	
	Solution sul;
	int res = sul.lengthOfLastWord(s);
	cout<<res<<endl;
	

	getchar();
	return 0;
}