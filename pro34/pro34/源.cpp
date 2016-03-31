#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid, low = 0, high = nums.size()-1;
		while(low <= high){
			mid = (low + high)/2;
			if(nums[mid] == target)
				break;
			else if(nums[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		int p1 = mid, p2 = mid;
		while((p1 > 0) && (nums[p1-1] == nums[p1]))
			p1 --;
		while((p2 < nums.size()-1) && (nums[p2+1] == nums[p2]))
			p2 ++;
		vector<int> res;
		if(low > high){
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		res.push_back(p1);
		res.push_back(p2);
		return res;
	}
	
};

int main(){
	Solution sul;
	int arr[10] = {1,2,3,4,5,7,8,8,8,10};
	vector<int> nums(arr, arr+10);
	int target = 10;
	vector<int> res = sul.searchRange(nums, target);
	for(int i = 0;i < res.size();i++)
		cout<<res[i]<<", ";
	cout<<endl;
	getchar();getchar();
	return 0;
}