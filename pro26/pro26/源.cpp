#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	    int i = 0;
		for (int n : nums)
			if (i == 0 || n > nums[i-1])
				nums[i++] = n;
		return i;
    }
};

int main(){
	int arr[10] = {1,1,2,2,4,4,6,6,6,10};
	vector<int> nums(arr, arr+10);
	Solution sul;
	int res = sul.removeDuplicates(nums);
	cout<<"--"<<res<<endl;
	getchar();getchar();
	return 0;
}