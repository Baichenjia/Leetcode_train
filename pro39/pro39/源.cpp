#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
		vector<vector<int>> totalRes;
		vector<int> res;
		int low = 0, high = A.size()-1;
		sort(A.begin(), A.end());
		find(A, totalRes, res, low, high, target);
		return totalRes;
    }

	void find(vector<int> &A, vector<vector<int>> &totalRes, vector<int> &res, int low, int high, int target){
		if(target == 0){
			totalRes.push_back(res);
		}
		for(int i = low; i < A.size() && target >= A[i]; ++i){
			res.push_back(A[i]);
			find(A, totalRes, res, i, high, target-A[i]);
			res.pop_back();
		}
	}
};

int main(){
	Solution sul;
	int arr[3] = {7, 3, 2};
	int target = 18;
	vector<int> candidates(arr, arr+3);
	vector<vector<int>> res = sul.combinationSum(candidates, target);
	for(int i = 0;i < res.size();i++){
		for(int j = 0;j < res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	getchar();getchar();
	return 0;
}

/*

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        if  (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }

	*/