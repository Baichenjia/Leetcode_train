#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
//分治算法  超时 回溯法
class Solution {
public:
    int uniquePaths(int m, int n) {
		int row = 0, col = 0;
		int count = 0;
		findPath(row, col, m, n, count);
		return count;
    }
	void findPath(int row, int col, int m, int n, int &count){
		cout<<row<<"  "<<col<<endl;
		if(row == m-1 && col == n-1){
			count++;
			return;
		}
		if(row < m-1)
			findPath(row+1, col, m, n, count);
		if(col < n-1)
			findPath(row, col+1, m, n, count);
	}
};*/

class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int>> vec;
		for(int i = 0;i < m;++i){
			vector<int> temp(n, 0);
			vec.push_back(temp);
		}
		for(int i = 0;i < m;++i)
			vec[i][0] = 1;
		for(int i = 0;i < n;++i)
			vec[0][i] = 1;
		for(int i = 1;i < m;++i){
			for(int j = 1;j < n;++j){
				vec[i][j] = vec[i-1][j] + vec[i][j-1];
			}
		}
		return vec[m-1][n-1];
	}
};



int main(){
	int m, n;
	cin>>m>>n;
	Solution sul;
	int count = sul.uniquePaths(m, n);
	cout<<count<<endl;

	getchar();getchar();
	return 0;
}