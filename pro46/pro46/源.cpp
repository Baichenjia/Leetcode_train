#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > res;
		int begin = 0;
		int end = num.size()-1;
		Allrange(res, num, begin, end);
		return res;
    }

	void Allrange(vector<vector<int>> &res, vector<int> &num, int begin, int end){
		if(begin == end){
			res.push_back(num);
		}
		else{
			for(int i = begin;i <= end; i++){
				swap(num[begin], num[i]);
				Allrange(res, num, begin+1, end);
				swap(num[begin], num[i]);
			}
		}
	}
};


int main(){
	int arr[] = {1, 2, 3, 4};
	vector<int> nums(arr, arr+4);
	Solution sul;
	vector<vector<int>> res = sul.permute(nums);
	for(int i = 0;i < res.size();i++){
		for(int j = 0;j < res[i].size();j++){
			cout<<res[i][j]<<"  ";
		}
		cout<<endl;
	}
	getchar();getchar();
	return 0;
}