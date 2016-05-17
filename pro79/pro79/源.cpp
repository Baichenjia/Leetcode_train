#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		if(board.size() == 0) return false;
		int m = board.size(), n = board[0].size();
		for(int i = 0;i < m;++i){
			for(int j = 0;j < n;++j){
				//board是原棋盘， word是要查找的单词，vec[i]代表当前遍历到的board上的坐标，index代表当前遍历到的word的下标
				bool flag = DFS(board, word, i, j, 0);
				if(flag)
					return true;
			}
		}
		return false;
    }

	bool DFS(vector<vector<char>> &board, string word, int x, int y, int index){
		if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '\0' || word[index] != board[x][y])
			return false;
		if(index == word.size()-1)
			return true;
		char c = board[x][y];
		board[x][y] = '\0';

		if(DFS(board, word, x-1, y, index+1) || DFS(board, word, x+1, y, index+1) || DFS(board, word, x, y-1, index+1) || DFS(board, word, x, y+1, index+1))
			return true;
		board[x][y] = c;
		return false;
	}
};

int main(){
	int arr[][4] = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	vector<vector<char>> board1;
	for(int i = 0;i < end(arr)-begin(arr);++i)
		board1.push_back(vector<char>(begin(arr[i]), end(arr[i])));
	vector<vector<char>> board2(board1);
	vector<vector<char>> board3(board1);

	string word1 = "ABCCED", word2 = "SEE", word3 = "ABCB";
	Solution sul;
	bool flag1 = sul.exist(board1, word1);
	bool flag2 = sul.exist(board2, word2);
	bool flag3 = sul.exist(board3, word3);

	if(flag1)  cout<<word1<<"\t  True"<<endl;  else  cout<<word1<<"\t  False"<<endl;
	if(flag2)  cout<<word2<<"\t  True"<<endl;  else  cout<<word2<<"\t  False"<<endl;
	if(flag3)  cout<<word3<<"\t  True"<<endl;  else  cout<<word3<<"\t  False"<<endl;

	getchar();
	return 0;
}