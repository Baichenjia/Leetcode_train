#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int p1 = 0, p2 = nums.size()-1;
        while(p1 <= p2){
            int mid = (p1 + p2) / 2;
            if(nums[mid] == target)   
				return mid;
            //情况1
            if(nums[p1] < nums[p2]){
                if(nums[mid] > target) 
					p2 = mid - 1;
                else
                    p1 = mid + 1;
            }
            //情况2
            else if(nums[mid] < nums[p2]){
                if(nums[mid] < target && nums[p2] >= target)  
					p1 = mid + 1;
                else  
					p2 = mid - 1;
            }
            //情况3
            else{  
                if(nums[p1] <= target && nums[mid] > target)     
					p2 = mid - 1;
                else  
					p1 = mid + 1;
            }
        }
        return -1;
	}
};


int main(){
	//int arr[3] = {3, 5, 1};
	//vector<int> nums(arr, arr+3);
	//int target = 3;
	//Solution sul;
	//int res = sul.search(nums, target);
	//cout<<res<<endl;
	int a = INT_MIN;
	cout<<a<<endl;
	if(a < 0) cout<<"yes"<<endl;
	
	getchar();getchar();
	return 0;

}