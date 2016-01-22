#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        int k1, k2, pSum;
		vector<vector<int>> reslist;
		if(nums.size() < 4)
			return reslist;
		vector<int> res;
		sort(nums.begin(), nums.end());
		for(int i = 0;i < nums.size()-3;i++){
			res.clear();
			for(int j = i+1;j < nums.size()-2;j++){
				k1 = j+1;k2 = nums.size()-1;
				while(k1 < k2){
					pSum = nums[k1] + nums[k2];
					if(pSum + nums[i] + nums[j] == target){ //ÕÒµ½Ò»¸ö
						res.clear();
						res.push_back(nums[i]);
						res.push_back(nums[j]);
						res.push_back(nums[k1]);
						res.push_back(nums[k2]);
						reslist.push_back(res);
						k1++;k2--;
						while((k1<k2) && (nums[k1+1] == nums[k1]))  k1++;
						while((k1<k2) && (nums[k2-1] == nums[k2]))  k2--;
					}
					else if(pSum + nums[i] + nums[j] < target){
						k1++;
					}
					else
						k2--;
				}
				while(j + 1 < nums.size()-2 && nums[j+1] == nums[j])  j++;
			}
			while(i + 1 < nums.size()-3 && nums[i+1] == nums[i])  i++;
		}
		sort(reslist.begin(), reslist.end());
		vector<vector<int>>::iterator iter = unique(reslist.begin(), reslist.end());
		reslist.erase(iter, reslist.end());
		return reslist;
    }

	
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
						int arr[4] = {nums[i], nums[j], nums[left], nums[right]};
						vector<int> vectemp(arr, arr+4);
                        total.push_back(vectemp);
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }

};


int main()
{
	Solution sul;
	int arr[6] = {1, 0, -1, 0, -2, 2};
	int target = 0;
	vector<int> nums(arr, arr+6);
	vector<vector<int>> res = sul.fourSum(nums, target);
	for(int i = 0;i < res.size();i++){
		for(int j = 0;j < 4;j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	getchar();getchar();
	return 0;
}