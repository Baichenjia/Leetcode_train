#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		if(nums.size() == 0)
			return ;
        int front = 0, current = 0,end = nums.size()-1;
		while(current <= end){
			if(nums[current] == 0){
				swap(nums[current], nums[front]);
				++current;
				++front;
			}
			else if(nums[current] == 1)
				++current;
			else{
				swap(nums[current], nums[end]);
				--end;
			}
		}
    }
};

int main(){
	int arr[] = {1,2,0,0,2,0,1,1,2,0,0,1,2,2,1};
	vector<int> vec(begin(arr), end(arr));
	Solution sul;
	sul.sortColors(vec);
	for(int i = 0;i < vec.size();++i)
		cout<<vec[i]<<" ";
	cout<<endl;

	getchar();
	return 0;
}