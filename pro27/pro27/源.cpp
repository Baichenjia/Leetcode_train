#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
		vector<int>::iterator iter = find(nums.begin(), nums.end(), val);
		if(iter == nums.end())
			return nums.size();
		int p1 = iter - nums.begin();
		int count = 1;
		while((++iter) != nums.end()){
			if(*iter == val){
				p1++;
				count++;
			}
		}
		int res = nums.size() - count;
		int p2 = nums.size()-1;
		while(count--){
			int temp = nums[p2];
			nums[p2] = nums[p1];
			nums[p1] = temp;
			p1--;p2--;
		}
		return res;
    }
};

int main(){
	Solution sul;
	int arr[5] = {0, 4, 0, 4, 3};
	vector<int> nums(arr, arr+5);
	int res = sul.removeElement(nums, 4);

	
	
	cout<<res<<endl;
	getchar();getchar();
	return 0;
}