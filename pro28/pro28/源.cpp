#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int *next = getnext(needle);
		int i = 0,j = 0;
		int size1 = haystack.size();
		int size2 = needle.size();
		while(i < size1 && j < size2){
			if(j == -1 || haystack[i] == needle[j]){
				i++;j++;
			}
			else
				j = next[j];
		}
		if(j == size2){
			return i-j;
		}
		return -1;
    }

	int* getnext(string str){
		int j = 0;
		int k = -1;
		int *next = new int[str.size()];
		for(int i = 0;i < str.size();i++) next[i] = -99;
		next[0] = -1;
		while(j < str.size()-1){
			if(k == -1 || str[j] == str[k])
				next[++j] = ++k;
			else
				k = next[k];
		}
		return next;
	}

};

int main(){
	string strLen, strKey;
	strLen = "mississippi";
	strKey = "issi";
	Solution sul;
	int res = sul.strStr(strLen, strKey);
	cout<<"res = "<<res<<endl;
	getchar();getchar();
	return 0;
}