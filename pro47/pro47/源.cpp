#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > res;
		int begin = 0;
		int end = num.size()-1;
		Allrange(res, num, begin, end);
		return res;
    }

	bool isswap(vector<int> &num, int begin, int k){
		for(int i = begin; i < k; i++)
			if(num[i] == num[k])
				return false;
		return true;
	}

	void Allrange(vector<vector<int>> &res, vector<int> &num, int begin, int end){
		if(begin == end){
			res.push_back(num);
		}
		else{
			for(int i = begin;i <= end; i++){
				if(isswap(num, begin, i)){
					swap(num[begin], num[i]);
					Allrange(res, num, begin+1, end);
					swap(num[begin], num[i]);
				}
			}
		}
	}
};*/


class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> > res;
		res.push_back(num);
		while(true){
			int p;
			bool flag = true;
			//寻找非递增的相邻两个数
			for(int i = num.size()-1;i > 0;i--){
				if(num[i] > num[i-1]){
					flag = false;
					p = i-1;
					break;
				}
			}
			//如果不存在，表明数组已经按照降序排序，退出
			if(flag)  
				break;
			//如果存在，从末尾开始寻找第一个大于该数的数，交换，P之后的数翻转
			//注意,P之后的数是按降序排序的
			for(int i = num.size()-1;i > p;i--){
				if(num[i] > num[p]){
					swap(num[i], num[p]);
					break;
				}
			}
			sort(num.begin()+p+1, num.end());
			res.push_back(num);
		}
		return res;
    }
};


int main(){
	int arr[] = {1, 2, 2};
	vector<int> nums(arr, arr+3);
	Solution sul;
	vector<vector<int>> res = sul.permuteUnique(nums);
	for(int i = 0;i < res.size();i++){
		for(int j = 0;j < res[i].size();j++){
			cout<<res[i][j]<<"  ";
		}
		cout<<endl;
	}
	getchar();getchar();
	return 0;
}