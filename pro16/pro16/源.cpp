#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int res=0, minerr = 9999;
		sort(nums.begin(), nums.end());
		for(int i = 0;i < nums.size();i++)
		{
			int j = i+1;
			int k = nums.size()-1;
			int currentValue = nums[i];
			while(j < k)
			{
				int sumjk = nums[j] + nums[k];
				int err = currentValue + sumjk - target;
				if(err < 0)
					j++;
				else
					k--;
				if(abs(err) < abs(minerr))
				{
					minerr = abs(err);
					res = currentValue + sumjk;
				}
			}
			while(i + 1 < nums.size() && nums[i+1] == nums[i])
				i++;
		}
		return res;
    }
};

int main()
{
	Solution sul;
	int arr[4] = {-1, 0, 1, -4};
	vector<int> vec(arr, arr+4);
	int res = sul.threeSumClosest(vec, 1);
	cout<<res<<endl;
	getchar();getchar();
	return 0;
}
