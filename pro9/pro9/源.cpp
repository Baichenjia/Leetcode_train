#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome2(int x) {
        if(x<0|| (x != 0 && x % 10 == 0)) return false;
        int sum = 0;
        while(x > sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
		//cout<<"x = "<<x<<endl;
		//cout<<"sum = "<<sum<<endl;
        return (x==sum)||(x==sum/10);
    }

	bool isPalindrome(int x){
		if(x < 0 || (x != 0 && x % 10 == 0)) return false;
		int sum = 0,y = x;
		while(x != 0){
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		cout<<"x = "<<x<<endl;
		cout<<"sum = "<<sum<<endl;
		return y==sum;
	}
};


int main(){
	Solution sul;
	int x;
	while(1){
		cin>>x;
		bool flag = sul.isPalindrome(x);
		if(flag)  cout<<"yes";
		else cout<<"no";
	}
	getchar();getchar();
	return 0;
}