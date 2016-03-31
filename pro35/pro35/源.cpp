#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        if(target < nums[low])  return 0;
        if(target > nums[high]) return nums.size();
        while(low <= high){
            mid = (low + high)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
        if(nums[high] < target)    
            return high+1;
        return high;
        
    }
};

int main(){
	Solution sul;
	int arr[2] = {1, 3};
	int target = 2;
	vector<int> nums(arr, arr+2);
	int res = sul.searchInsert(nums, target);
	cout<<res<<endl;
	getchar();getchar();return 0;
}