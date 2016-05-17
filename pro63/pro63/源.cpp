#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
		if(m == 0)  return 0;
		int n = obstacleGrid[0].size();
		vector<vector<int>> vec;
		for(int i = 0;i < m;i++){
			vector<int> temp(n, 0);
			vec.push_back(temp);
		}
		bool flag = false;
		for(int i = 0;i < m;++i){
			if(obstacleGrid[i][0] == 1)
				flag = true;
			if(!flag)
				vec[i][0] = 1;
			else
				vec[i][0] = 0;
		}
		flag = false;
		for(int i = 0;i < n;++i){
			if(obstacleGrid[0][i] == 1)
				flag = true;
			if(!flag)
				vec[0][i] = 1;
			else
				vec[0][i] = 0;
		}
		for(int i = 1;i < m;++i){
			for(int j = 1;j < n;++j){
				if(obstacleGrid[i][j] == 1)  //ÕÏ°­
					vec[i][j] = 0;
				else
					vec[i][j] = vec[i-1][j] + vec[i][j-1];
			}
		}
		/*
		//print solution
		for(int i = 0;i < m;++i){
			for(int j = 0;j < n;++j){
				cout<<vec[i][j]<<'\t';
			}
			cout<<endl;
		}*/

		return vec[m-1][n-1];
    }
};


int main(){
	vector<vector<int>> grid;
	int arr1[5] = {0, 0, 1, 0, 0};
	int arr2[5] = {0, 1, 0, 0, 0};
	int arr3[5] = {0, 0, 0, 1, 0};
	int arr4[5] = {0, 0, 1, 0, 0};
	vector<int> temp1(arr1, arr1+5);
	vector<int> temp2(arr2, arr2+5);
	vector<int> temp3(arr3, arr3+5);
	vector<int> temp4(arr4, arr4+5);
	grid.push_back(temp1);
	grid.push_back(temp2);
	grid.push_back(temp3);
	grid.push_back(temp4);

	Solution sul;
	int res = sul.uniquePathsWithObstacles(grid);
	cout<<"res = "<<res<<endl;

	getchar();getchar();
	return 0;
}