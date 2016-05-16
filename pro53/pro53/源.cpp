#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
		vector<int> vec(n, 0);
		vec[0] = nums[0];
		int maxnum = vec[0];
		for(int i = 1;i < n;++i){
			if(vec[i-1] <= 0)
				vec[i] = nums[i];
			else
				vec[i] = vec[i-1] + nums[i];
			maxnum = max(vec[i], maxnum);
		}
		return maxnum;
    }
};


int main(){
	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> nums(begin(arr), end(arr));
	Solution sul;
	int res = sul.maxSubArray(nums);
	cout<<res<<endl;
	getchar();
	return 0;
}