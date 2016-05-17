#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		int a1 = 1, a2 = 2;
		if(n == 1)
			return a1;
		else if(n == 2)
			return a2;
		int res = 0;
		for(int i = 3;i <= n;++i){
			res = a1 + a2;
			a1 = a2;
			a2 = res;
		}
        return res;
    }
};


int main(){
	int n;
	Solution sul;
	while(true){
		cin>>n;
		int res = sul.climbStairs(n);
		cout<<res<<endl;
	}
	getchar();
	return 0;
}