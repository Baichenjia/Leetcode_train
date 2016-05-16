#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
		for(int i = 0;i < n;++i){
			vector<int> temp(n, 0);
			res.push_back(temp);
		}
		int start = 0;
		int count = 1;
		while(start < n/2){
			for(int i = start;i <= n-start-1;++i)
				res[start][i] = count++;
			for(int i = start+1;i <= n-start-1;++i)
				res[i][n-start-1] = count++;
			for(int i = n-start-2;i >= start;--i)
				res[n-start-1][i] = count++;
			for(int i = n-start-2;i >= start+1;--i)
				res[i][start] = count++;
			start++;
		}
		if((n & 0x1) == 1)
			res[n/2][n/2] = count;
		return res;
    }
};

int main(){
	int n = 0;
	Solution sul;
	vector<vector<int>> res = sul.generateMatrix(n);
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j)
			cout<<res[i][j]<<'\t';
		cout<<endl;
	}
	getchar();
	return 0;
}