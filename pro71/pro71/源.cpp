#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
		string::iterator it = path.end()-1;
		string str;
		while(it != path.begin() && *it == '/')
			it--;
		bool flag = true;
		while(it != path.begin() && *it != '/'){
			while(*it == '.'){
				flag = false;
				it--;
			}
			if(!flag){
				str += '.' + str;
				it++;
			}
			else
				str = *it + str;
			it--;
		}
		if(*it != '/')
			str = *it + str;
		str = "/" + str;
		return str;
    }
};

int main(){
	string str = "/...........hidden";
	Solution sul;
	string res = sul.simplifyPath(str);
	cout<<res<<endl;
	
	getchar();
	return 0;
}