#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		int n = str.length();
		string new_str = "";
		int index, end=n;
		bool flag = true;
		int index2=0;
		for(int i = 0;i < n;i++){
			if(str[i] == 32){
				index2 = i+1;
				continue;
			}
			break;
		}
		if(((str[index2] != 43)&&(str[index2] != 45)) && ((str[index2]<48)||(str[index2]>57)))
			return 0;
		for(int i = index2;i<n;i++){
			if((str[i] == 43) || (str[i] == 45)){   //确定符号
				if(str[i] == '+')  flag = true;
				else flag = false;
				index = i+1;
				break;
			}
			if((str[i] >= 48) && (str[i] <= 57)){  //如果并未指明符号数字部分开始
				index = i;
				break;
			}
		}
		for(int i = index;i < n;i++){   //处理前面的0
			if(str[i] == 48){
				index++;
				continue;
			}
			break;
		}
		for(int i = index;i < n;i++){
			if((str[i] < 48) || (str[i] > 57)){   //说明输入不符合要求
				end = i+1;
				break;
			}
			else
				new_str += str[i];
		}
		long long res = 0;
		for(int i = 0;i < (end<new_str.length()?end:new_str.length());i++){
			res += (new_str[i] - 48) * pow(10, new_str.length()-i-1);
			if((abs(res) > INT_MAX) && (flag == true))
				return INT_MAX;
			else if((abs(res)-1 > INT_MAX) && (flag == false))
				return INT_MIN;
			else{}
		}
		return int((flag==true)?res:-res);
    }
};

int main(){
	Solution sul;
	string str = "18446744073709551617";
	int res = sul.myAtoi(str);
	cout<<res<<endl;
	getchar();getchar();
	return 0;
}


//
//int myAtoi(string str) {
//    long result = 0;
//    int indicator = 1;
//    for(int i = 0; i<str.size();)
//    {
//        i = str.find_first_not_of(' ');
//        if(str[i] == '-' || str[i] == '+')
//            indicator = (str[i++] == '-')? -1 : 1;
//        while('0'<= str[i] && str[i] <= '9') 
//        {
//            result = result*10 + (str[i++]-'0');
//            if(result*indicator >= INT_MAX) return INT_MAX;
//            if(result*indicator <= INT_MIN) return INT_MIN;                
//        }
//        return result*indicator;
//    }
//}