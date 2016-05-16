#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*//BFS
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
		vector<vector<int>> matrix;
		for(unsigned int i = 0;i < n;++i){
			vector<int> vec(n, 0);
			matrix.push_back(vec);
		}
		for(int i = 0;i < n;++i){
			for(int j = 1;j <= nums[i];++j){
				if(i + j < n){
					matrix[i][i+j] = 1;
					matrix[i+j][i] = 1;
				}
			}
		}
		queue<vector<int>> workQueue;
		vector<int> init;
		init.push_back(n-1);
		init.push_back(0);  //步数
		workQueue.push(init);
		while(!workQueue.empty()){
			vector<int> front = workQueue.front();  //队首元素
			workQueue.pop();
			int node = front[0];
			int count = front[1];
			if(node == 0)
				return count;
			for(int i = 0;i < node;i++){
				if(matrix[i][node] == 1){
					vector<int> next;
					next.push_back(i);
					next.push_back(count+1);
					workQueue.push(next);
				}
			}
		}
		return 0;
    }
};*/


/*//DFS
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
		vector<vector<bool>> matrix;
		for(unsigned int i = 0;i < n;++i){
			vector<bool> vec(n, false);
			matrix.push_back(vec);
		}
		for(int i = 0;i < n;++i){
			for(int j = 1;j <= nums[i];++j){
				if(i + j < n){
					matrix[i][i+j] = true;
					matrix[i+j][i] = true;
				}
			}
		}
		stack<pair<int, int>> workStack;
		pair<int, int> init(n-1, 0);
		workStack.push(init);
		while(!workStack.empty()){
			pair<int, int> front = workStack.top();
			workStack.pop();
			int node = front.first;
			int count = front.second;
			if(node == 0)
				return count;
			vector<pair<int, int>> neighbor;
			for(int i = 0;i < node;i++){
				if(matrix[i][node] == true){
					pair<int, int> temp(i, count+1);
					neighbor.push_back(temp);
				}
			}
			bool (*pf)(const pair<int, int>&, const pair<int, int>&);
			pf = &Solution::cmp;
			sort(neighbor.begin(), neighbor.end(), pf);
			for(pair<int, int> &t: neighbor)
				workStack.push(t);
		}
		return 0;
    }

	static bool cmp(const pair<int, int> &a1, const pair<int, int> &a2){
		if(a1.first > a2.first)
			return true;
		else if(a1.first == a2.first){
			if(a1.second > a2.second){
				return true;
			}
			return false;
		}
		else
			return false;
	}

};*/


class Solution {
public:
	int jump(vector<int> &nums) {
		int n = nums.size();
		if(n < 2)
			return 0;
		int level = 0, currentMax = 0,i = 0, nextMax = 0;

		while(currentMax-i+1 > 0){       //nodes count of current level>0
			level++;
			for(;i <= currentMax;i++){   //traverse current level , and update the max reach of next level
				nextMax = max(nextMax,nums[i]+i);
				if(nextMax >= n-1)
					return level;   // if last element is in level+1,  then the min jump=level 
			}
            currentMax=nextMax;
		}
		return 0;
	}
};



int main(){
	int arr[] = {2, 3, 1, 1, 4};
	vector<int> nums(begin(arr), end(arr));
	Solution sul;
	int res = sul.jump(nums);
	cout<<res<<endl;
	
	getchar();
	return 0;
}