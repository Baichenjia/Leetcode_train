#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() < num2.size())
			swap(num1, num2);
		int len1 = num1.size() + num2.size()-1;
		int len2 = num2.size()-1;
		vector<vector<int>> T;
		for(int i = 0;i < num2.size();i++){
			vector<int> temp(len1+1, 0);
			int a = num2[num2.size()-i-1]-'0';   //乘数的最后一位
			int j = len1 - i;
			int count = 0;
			for(int k = num1.size()-1;k >= 0;k--){
				temp[j] = count + a * (num1[k]-'0');
				count = temp[j] / 10;
				temp[j] = temp[j] % 10;
				j--;
			}
			temp[j] += count;
			T.push_back(temp);
		}
		//输出
		for(int i = 0;i < T.size();i++){
			for(int k = 0;k < T[i].size();k++){
				cout<<T[i][k]<<"  ";
			}
			cout<<endl;
		}
		//累加
		vector<int> res(len1+1, 0);
		for(int i = 0;i < T.size();i++){
			int count = 0;
			for(int j = len1;j >= 0;j--){
				res[j] += count + T[i][j];
				count = res[j] / 10;
				res[j] = res[j] % 10;
			}
		}
		
		cout<<endl;
		for(int i = 0;i < res.size();i++)
			cout<<res[i]<<"  ";
		cout<<endl;
		string s;
		int p = 0;
		while(p < res.size()-1 && res[p] == 0 )  
			p++;
		for(;p < res.size();p++)
			s += ('0'+ res[p]);
		return s;
    }

	string multiply1(string num1, string num2) {
	    string sum(num1.size() + num2.size(), '0');
		for (int i = num1.size() - 1; i >= 0;--i) {
			int carry = 0;

			for(int k = 0;k < sum.size();k++)
				cout<<sum[k]<<"  ";
			cout<<endl;
			
			for (int j = num2.size() - 1; j >= 0; --j) {
				int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
				cout<<"i = "<<i<<", j = "<<j<<",  i+j+1 = "<<i+j+1<<", num1[i] = "<<num1[i]<<", num2[j] = "<<num2[j]<<", carry = "<<carry<<", tmp = "<<tmp<<endl;
				sum[i + j + 1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			sum[i] += carry;
		}

	    size_t startpos = sum.find_first_not_of("0");
		if (string::npos != startpos) {
			return sum.substr(startpos);
		}
		return "0";
	}
};

int main(){
	string str1 = "123456789"; 
	string str2 = "987654321";
	Solution sul;
	string res = sul.multiply1(str1, str2);
	cout<<res<<endl;
	return 0;
}