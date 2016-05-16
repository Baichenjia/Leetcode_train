#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> A(matrix);
		int n = matrix.size();
		for(unsigned int i = 0;i < matrix.size();++i){
			for(unsigned int j = 0;j < matrix[i].size();++j){
				matrix[i][j] = A[n-j-1][i];
			}
		}
    }
};


int main(){


}