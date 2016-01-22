#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vecResult;
		if(nums.size() < 3)
			return vecResult;
		vector<int> vecTriple(3, 0);
		sort(nums.begin(), nums.end());
		int iCount = nums.size() - 2;
		int iCurrentValue = nums[0];
		for(int i = 0;i < iCount;i++){
			if(i && nums[i] == iCurrentValue) { // (2) trick 2: trying to avoid repeating triples
				continue;
         }
         // do 2 sum
         vecTriple[0] = nums[i];
         int j = i + 1;       
		 int k = nums.size() - 1;
		 while(j < k) {
			int iSum = nums[j] + nums[k];              
			if(iSum + vecTriple[0] == 0) {
				vecTriple[1] = nums[j];
                vecTriple[2] = nums[k];
                vecResult.push_back(vecTriple); // copy constructor
                ++j;
                --k;
            }
            else if(iSum + vecTriple[0] < 0)
                ++j;
            else
                --k;
			}
			iCurrentValue = nums[i]; //该数已经经过判断，下次如果还遇到该数则跳过。由于已经排序，所以如果该数有重复，将会在相邻的地方重复
		}
		sort(vecResult.begin(), vecResult.end());
		vecResult.erase(unique(vecResult.begin(), vecResult.end()), vecResult.end());
		return vecResult;
    }
};

int main()
{
	Solution sul;
	int arr[6] = {-1, 0, 1, 2, -1, -4};
	vector<int> arrvec(arr, arr+6);
	vector<vector<int>> res = sul.threeSum(arrvec);
	for(int i = 0;i < res.size(); i++)
	{
		for(int j = 0;j < 3;j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	getchar();getchar();
	return 0;
}