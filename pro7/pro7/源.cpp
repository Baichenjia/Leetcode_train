#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>
using namespace std;

class Solution {
public:
    int reverse(long long x) {      
        bool flag = x>0?true:false;
		x = (flag==true?x:-x);
		string str = "";
		while(true){
			str += (x % 10 + '0');
			x = x / 10;
			if(x == 0)
				break;
		}
		double res = 0,len = str.length();
		for(int i = 0;i < str.length();i++)
		{
			if(str[i] == 0)
				continue;
			res += (str[i] - '0') * (double)pow(10, (str.length() - i - 1)); 
		    if((flag && res >= 2147483647) || (!flag && res >= 2147483648)){
			    return 0;
		    }
		}
		return int(flag==true?res:(-res));
    }
	//*************сп╢М
    int reverse2(int x) {
        bool neg=false;
        if (x < 0) neg = true, x = -x;
        unsigned int ret = 0;
        while (x / 10){
            ret = ret*10+ x%10;
            x = x / 10;
        }
        ret =ret*10+x;
        if (ret>0x7fffffff) return 0; //overflow check.
        if (neg) return -(int)ret;
        return (int)ret;
    }
};

int main()
{
	Solution sul;
	long long y = 2147483648;
	long long x = -y;
	int res = sul.reverse2(x);
 	cout<<res<<endl;







	getchar();getchar();
	return 0;
}