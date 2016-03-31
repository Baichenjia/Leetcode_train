#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		string str1 = "1", str2;n--;
		while(n--){
			str2 = "";
			char p1 = str1[0]; int count = 0;
			for(int i = 0;i < str1.size();i++){
				if(p1 == str1[i])  count++;
				else{
					str2 += count + '0';
					str2 += p1;
					p1 = str1[i--];
					count = 0;
				}
			}
			str2 += count + '0';
			str2 += p1;
			swap(str1, str2);
			//cout<<str1<<endl;
		}
		return str1;
    }
};

int main(){
	Solution sul;
	int n;cin>>n;
	sul.countAndSay(n);
	getchar();getchar();
	return 0;
}