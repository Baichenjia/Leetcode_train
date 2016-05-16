#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solveNQueens2(int n) {
        vector<int> arr(n);
        int res = 0, start = 0, end = n-1;
        DFS(res, arr, start, end);
        return res;
    }

    //深度优先搜索  
    //当前已经搜索到底start行，总共有end行
    void DFS(int &res, vector<int> &arr, int start, int end)
    {
        if(start == end+1){
            res++;
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
};




int main(){
    Solution sul;
    int n = 4;
    int res = sul.solveNQueens2(n);
	cout<<res<<endl;

    getchar();
    return 0;
}