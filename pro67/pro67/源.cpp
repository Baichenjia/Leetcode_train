#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n, n1 = a.length(), n2 = b.length();
		if(n1 > n2){
			int len = n1 - n2;
			while(len--)
				b = "0" + b;
			n = n1;
		}
		else{
			int len = n2 - n1;
			while(len--)
				a = "0" + a;
			n = n2;
		}
		int w = 0;
		string str;
		for(int i = n-1;i >= 0;i--){
			int temp = (a[i]-'0') + (b[i]-'0') + w;
			char c =  (temp % 2) + '0';
			w = temp / 2;
			str = c + str;
		}
		if(w > 0)
			str = to_string(w) + str;
		return str;
	}
};


int main(){
	string str1 = "11011";
	string str2 = "1111101";
	Solution sul;
	string str = sul.addBinary(str1, str2);
	cout<<str<<endl;

	getchar();
	return 0;
}