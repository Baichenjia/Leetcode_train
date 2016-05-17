#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	//1. 位运算
    vector<vector<int>> subsets1(vector<int>& nums) {
		int n = nums.size(), count = 0, total = static_cast<int>(pow(2, nums.size()));
        vector<vector<int>> res(total);
		while(count < total){
			vector<int> &res_vec = res[count]; 
			handel(res_vec, nums, count, n);
			++count;
		}
		return res;
    }
	void handel(vector<int> &res_vec, vector<int> &nums, int count, int n){
		int c = 1;
		for(int i = 0;i < n;++i){
			if(c & count)
				res_vec.push_back(nums[n-i-1]);
			c = c << 1;
		}
		sort(res_vec.begin(), res_vec.end());
	}

	//2.递归回溯
    vector<vector<int>> subsets2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;  
        genSubsets(nums, 0, sub, subs);
        return subs; 
    }
    void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            genSubsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
	

	/*
	This problem can also be solved iteratively. Take [1, 2, 3] in the problem statement as an example. The process of generating all the subsets is like:

	Initially: [[]]
	Adding the first number to all the existed subsets: [[], [1]];
	Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
	Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
	Have you got the idea :-)

	The code is as follows.
	*/
    vector<vector<int>> subsets3(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]);         //复制
                subs.back().push_back(nums[i]);  //添加元素
            }
        }
        return subs;
    }	
};

int main(){
	int arr[] = {1, 2, 3};
	vector<int> vec(begin(arr), end(arr));

	Solution sul;
	vector<vector<int>> res = sul.subsets2(vec);
	//sul.handel(vec, 3, 3);
	
	for(size_t i = 0;i < res.size();++i){
		for(size_t j = 0;j < res[i].size();++j){
			cout<<res[i][j]<<"  ";
		}
		cout<<endl;
	}
	getchar();
	return 0;
}


