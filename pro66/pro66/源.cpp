#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		int c = 1;
		for(int i = n-1;i >= 0;--i){
			int temp = digits[i] + c;
			c = (digits[i] + c) / 10;
			digits[i] = temp % 10;
		}
		if(c > 0)
			digits.insert(digits.begin(), c);
		return digits;
    }
};


int main(){
	int arr[] = {9};
	vector<int> vec(begin(arr), end(arr));
	Solution sul;
	vector<int> res = sul.plusOne(vec);
	for(auto a: res)
		cout<<a<<"  ";
	cout<<endl;
	getchar();
	return 0;
}