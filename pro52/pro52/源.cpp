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

    //�����������  
    //��ǰ�Ѿ���������start�У��ܹ���end��
    void DFS(int &res, vector<int> &arr, int start, int end)
    {
        if(start == end+1){
            res++;
            return ;
        }
        //ѭ��0-end����ʾӦ�ø���start�еı��Ϊ i ��λ�÷��ûʺ�
        for(int i = 0; i <= end; ++i){
            if(isvalid(arr, start, i)){
                arr[start] = i;
                DFS(res, arr, start+1, end);
            }
        }
    }

    //��ǰ���õ���row�У�Ҫ�ڵ�row�еĵ�col��λ�÷��ûʺ󡣸ú���������ַ��÷����Ƿ�Ϸ�
    bool isvalid(vector<int> &arr, int row, int col){
        for(int i = 0;i < row;i++){
            //�Ƿ���ͬһ�У� �Ƿ���ͬһ���Խ�����
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