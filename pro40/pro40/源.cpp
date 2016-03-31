#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void find1(vector<int> &A, vector<vector<int>> &totalres, vector<int> &res, int low, int high, int target){
		if(target == 0){
			if(find(totalres.begin(), totalres.end(), res) == totalres.end())
				totalres.push_back(res);
		}
		for(unsigned int i = low;i < A.size() && target >= A[i];i++){
			res.push_back(A[i]);
			find1(A, totalres, res, i+1, high, target-A[i]);
			res.pop_back();
		}
	}
	
    vector<vector<int> > combinationSum(vector<int> &nums, int target) 
    {
        vector<vector<int> > totalres;
        sort(nums.begin(), nums.end());
        vector<int> res;
		int low = 0, high = nums.size()-1;
        find1(nums, totalres, res, low, high, target);
        return totalres;
    }
};


int main(){
	int arr[7] = {10, 1, 2, 7, 6, 1, 5};
	vector<int> A(arr, arr+7);
	int target = 8;
	sort(A.begin(), A.end());
	Solution sul;
	vector<vector<int>> res = sul.combinationSum(A, target);
	for(unsigned int i = 0;i < res.size();i++){
		for(unsigned int j = 0;j < res[i].size();j++){
			cout<<res[i][j]<<"  ";
		}
		cout<<endl;
	}
	getchar();getchar();
	return 0;
}
