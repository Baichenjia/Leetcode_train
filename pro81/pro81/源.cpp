#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
			return false;
		int low = 0, high = nums.size()-1, mid;
		while(low <= high){
			mid = (low + high) / 2;
			if(nums[mid] == target)
				return true;
			if(nums[low] < nums[high]){
				if(nums[mid] > target)
					high = mid - 1;
				else
					low = mid + 1;
			}
			else if(nums[low] == nums[high] && nums[low] == nums[mid])
			{
				for(int i = 0;i < nums.size();++i)
					if(nums[i] == target)
						return true;
				return false;
			}
			else if(nums[mid] <= nums[high]){
				if(target > nums[mid] && target <= nums[high]){
					low = mid + 1;
				}
				else{
					high = mid - 1;
				}
			}
			else if(nums[mid] >= nums[low]){
				if(target >= nums[low] && target < nums[mid]){
					high = mid - 1;
				}
				else{
					low = mid + 1;
				}
			}
		}//while
		return false;
    }
};
/*
class Solution {
public:
  bool search(int A[], int n, int target) {
    int lo =0, hi = n-1;
    int mid = 0;
    while(lo<hi){
          mid=(lo+hi)/2;
          if(A[mid]==target) return true;
          if(A[mid]>A[hi]){
              if(A[mid]>target && A[lo] <= target) hi = mid;
              else lo = mid + 1;
          }else if(A[mid] < A[hi]){
              if(A[mid]<target && A[hi] >= target) lo = mid + 1;
              else hi = mid;
          }else{
              hi--;
          }

    }
    return A[lo] == target ? true : false;
  }
};*/

int main(){
	int arr[] = {1,1,3,1};
	vector<int> nums(begin(arr), end(arr));
	Solution sul;
	int target = 3;
	bool flag = sul.search(nums, target);
	if(flag)  
		cout<<"target = "<<target<<":  yes"<<endl;
	else  
		cout<<"target = "<<target<<":  no"<<endl;

	getchar();
	return 0;
}