#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool solveSudoku(vector<vector<char>> &board, int i, int j) {
        if(i == 9)  return true;
        if(j == 9)  return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);
        
        for(char c = '1';c <= '9';c++){
            if(check(board, i, j, c)){
                board[i][j] = c;
                if(solveSudoku(board, i, j+1))  return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool check(vector<vector<char>> &board, int i, int j, char val){
        int row = i - i%3, col = j-j%3;
        for(int x = 0;x < 9;x++)  if(board[x][j] == val) return false;  //检查当前行是否符合条件
        for(int y = 0;y < 9;y++)  if(board[i][y] == val) return false;  //检查当前列是否符合条件
        //检查当前元素所在的正方形块儿是否符合条件
        for(int x = 0;x < 3;x++){
            for(int y = 0;y < 3;y++){
                if(board[row+x][col+y] == val)  return false;
            }
        }
        return true;
    }
};

int main(){
	return 0;
}