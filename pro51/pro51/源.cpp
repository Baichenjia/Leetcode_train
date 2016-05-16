#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
		vector<vector<int>> res;
		vector<int> arr;
		int end = n-1;
		int start = 0;
		for(int i = 0;i < n;++i)
			arr.push_back(i);
		Permutation(res, arr, start, end);
		convertSol(res, sol);
		return sol;
    }

	void convertSol(vector<vector<int>> &res, vector<vector<string>> &sol){
		for(int i = 0;i < res.size();++i){
			vector<string> vec;
			for(int j = 0;j < res[i].size();++j){
				int pos = res[i][j];
				int k = 0;
				string str;
				while(k < pos){
					str += ".";
					++k;
				}
				str += "Q";
				++k;
				while(k < res[i].size()){
					str += '.';
					++k;
				}
				vec.push_back(str);
			}
			sol.push_back(vec);
		 }
	}

	void Permutation(vector<vector<int>> &res, vector<int> &arr, int start, int end){
		if(start == end){
			bool flag = true;
			for(int i = 0;i < end;++i){
				for(int j = 0;j <= end;++j){
					if(i != j && (abs(arr[i] - arr[j]) == abs(i-j))){
						flag = false;
						break;
					}//if
				}//for
				if(!flag)
					break;
			}//for
			if(flag)
				res.push_back(arr);
		}

		for(int i = start;i <= end;i++){
			swap(arr[i], arr[start]);
			Permutation(res, arr, start+1, end);
			swap(arr[i], arr[start]);
		}
	}

};
*/

/*
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
		vector<vector<int>> res;
		vector<int> arr(n);
		int start = 0, end = n-1;
		DFS(res, arr, start, end);
		convertSol(res, sol);
		return sol;
    }

	//深度优先搜索  
	//当前已经搜索到底start行，总共有end行
	void DFS(vector<vector<int>> &res, vector<int> &arr, int start, int end)
	{
		if(start == end+1){
			res.push_back(arr);
			return ;
		}
		//循环0-end，表示应该给第start行的编号为 i 的位置放置皇后
		for(int i = 0; i <= end; ++i){
			if(isvalid(arr, start, i)){
				arr[start] = i;
				DFS(res, arr, start+1, end);
			}
		}
	}

	//当前放置到第row行，要在第row行的第col的位置放置皇后。该函数检测这种放置方法是否合法
	bool isvalid(vector<int> &arr, int row, int col){
		for(int i = 0;i < row;i++){
			//是否在同一列？ 是否在同一条对角线上
			if(arr[i] == col || abs(i-row) == abs(arr[i]-col)){
				return false;
			}
		}
		return true;
	}


	void convertSol(vector<vector<int>> &res, vector<vector<string>> &sol){
		for(int i = 0;i < res.size();++i){
			vector<string> vec;
			for(int j = 0;j < res[i].size();++j){
				int pos = res[i][j];
				int k = 0;
				string str;
				while(k < pos){
					str += ".";
					++k;
				}
				str += "Q";
				++k;
				while(k < res[i].size()){
					str += '.';
					++k;
				}
				vec.push_back(str);
			}
			sol.push_back(vec);
		 }
	}
};
*/






int main(){
	Solution sul;
	int n = 4;
	vector<vector<string>> res = sul.solveNQueens(n);
	for(int i = 0;i < res.size();++i){
		cout<<"------------"<<endl;
		for(int j = 0;j < res[i].size();++j)
			cout<<res[i][j]<<endl;
		cout<<endl;
	}

	getchar();
	return 0;
}