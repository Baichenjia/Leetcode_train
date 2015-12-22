#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
		bool flag = true;
		for(unsigned int i = 0;i < nums.size();i++)
        {
			for(unsigned int j = i+1;j < nums.size();j++)
            {
                if(nums[i] + nums[j] == target)
                {
					res.push_back(i+1);
					res.push_back(j+1);
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
        }
		return res;
    }

	 vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> v;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                v.push_back(m[nums[i]]);
                v.push_back(i+1);
                return v;
            }else{
                m[target - nums[i]] = i+1;
            }
        }
    }
};

int main()
{
	Solution s;
	int arr[] = {3,2,4};
	vector<int> num(arr,arr+sizeof(arr)/sizeof(int));
	vector<int> res = s.twoSum3(num, 6);
	cout<<res[0]<<" "<<res[1]<<endl;
	getchar();
	return 0;
}