#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	//1. 自己写的，效率低
    int removeDuplicates1(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		int last = nums.back() + 1;
		int key = nums[0], count = 1, delcount = 0;
		for(int i = 1; i < nums.size();++i){
			if(nums[i] == key){
				++count;
				if(count > 2){
					nums[i] = last;
					++delcount;
				}
			}
			else{
				key = nums[i];
				count = 1;
			}
		}
		sort(nums.begin(), nums.end());
		return nums.size()-delcount;
    }

	//2. 高效
	int removeDuplicates(vector<int>& nums) {
		int i = 0;
		for (int n : nums)
			if (i < 2 || n > nums[i-2])
			  nums[i++] = n;
		return i;
	}
};

int main(){
	int arr[] = {1,1,1,2,2,2,2,3,3,4,5,6,6,7,8,9,9,9};
	vector<int> vec(begin(arr), end(arr));
	Solution sul;
	int n = sul.removeDuplicates(vec);
	for(int i = 0;i < n;++i)
		cout<<vec[i]<<" ";
	cout<<endl;

	getchar();
	return 0;
}