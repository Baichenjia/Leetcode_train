#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> vec(grid);
		if(grid.size() == 0)   return 0;
		int m = grid.size(), n = grid[0].size();
		for(int i = 1;i < m;++i)
			vec[i][0] += vec[i-1][0];
		for(int j = 1;j < n;++j)
			vec[0][j] += vec[0][j-1];
		for(int i = 1;i < m;++i){
			for(int j = 1;j < n;++j){
				vec[i][j] += min(vec[i-1][j], vec[i][j-1]);
			}
		}

		for(int i = 0;i < m;++i){
			for(int j = 0;j < n;++j)
				cout<<vec[i][j]<<'\t';
			cout<<endl;
		}
		return vec[m-1][n-1];
    }
};

int main(){
	vector<vector<int>> grid;
	for(int i = 0;i < 4;++i){
		vector<int> temp;
		for(int j = 0;j < 5;++j)
			temp.push_back(i * 4 + j);
		grid.push_back(temp);
	}
	Solution sul;
	int res = sul.minPathSum(grid);
	cout<<res<<endl;

	return 0;
}