#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if((x - 0.0 > -0.0000001) && (x - 0.0 < 0.0000001))
            return 0;
        if(n == 0)
            return 1;
        bool flag = true;
		long long n1 = labs(n);
		if(n < 0)  flag = false;
        double res = 1.0;
        while(n1--){
            res *= x;
        }
        if(!flag)  res = 1.0/res;
        return res;
    }
};

int main(){
	Solution sul;
	double res = sul.myPow(30.0001, -3);
	cout<<res<<endl;
	getchar();getchar();
	return 0;
}