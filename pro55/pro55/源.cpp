#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
		int level = 0, currentMax = 0, i = 0, nextMax = 0;
		while(currentMax-i+1 > 0){
			level++;
			for(;i <= currentMax;++i){
				nextMax = max(nextMax, nums[i]+i);
				if(nextMax >= n-1)
					return true;
			}
			currentMax = nextMax;
		}
		return false;
    }
};

int main(){
	int arr[] = {3, 2, 1, 0, 4};
	vector<int> nums(begin(arr), end(arr));
	Solution sul;
	bool flag = sul.canJump(nums);
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	getchar();
	return 0;
}