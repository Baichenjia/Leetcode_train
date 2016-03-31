#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		if(nums.size() == 0 || nums.size() == 1)  return ;
		if(nums.size() == 2){
			swap(nums[0], nums[1]);
			return ;
		}
		vector<int>::iterator front = nums.end()-2;
        vector<int>::iterator end = nums.end()-1;
		
		while((*front >= *(front+1)) && (front != nums.begin())){
			front--;
		}
		if(front == nums.begin() && *front > *(front+1)){
			sort(nums.begin(), nums.end());
			return ;
		}
		while(*end <= *front){
			end--;
		}
		int temp = *front;
		*front = *end;
		*end = temp;
		sort(front+1, nums.end());	
    }
};

int main(){
	Solution sul;
	int arr[5] = {4, 2, 4, 4, 3};
	vector<int> nums(arr, arr+5);
	sul.nextPermutation(nums);
	for(int i = 0;i < nums.size();i++){
		cout<<nums[i]<<endl;
	}
	getchar();getchar();
	return 0;
}