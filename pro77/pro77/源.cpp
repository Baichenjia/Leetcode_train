#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> vec;
		int start = 1;
		handel(res, vec, n, k, start);

		return res;
    }
	void handel(vector<vector<int>> &res, vector<int> &vec, int n, int k, int start){
		if(vec.size() == k){
			res.push_back(vec);
			return ;
		}
		for(int i = start; i <= n;++i){
			vec.push_back(i);
			handel(res, vec, n, k, i+1);
			vec.pop_back();
		}
	}
};


int main(){
	Solution sul;
	int n = 4, k = 2;
	vector<vector<int>> res = sul.combine(n, k);
	
	for(int i = 0;i < res.size();++i){
		for(int j = 0;j < res[i].size();++j){
			cout<<res[i][j]<<'\t';
		}
		cout<<endl;
	}
	getchar();
	return 0;
}